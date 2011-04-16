// Program Arguments
//
// Copyright (C) 2004-2011
// Center for Perceptual Systems
// University of Texas at Austin
//
// contact: jeffsp@gmail.com

#ifndef ARGV_H
#define ARGV_H

#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace horny_toad
{

/// @brief Arg command line arg
///
/// An 'Arg' specifies an option, an option with an option argument, or an
/// argument that is not an option.
/// Terms
///
/// OPTION: command line option, like '-h' or '--radius=1.2'
///
/// OPTION ARGUMENT: the optional argument of an option, like '1.2'
/// in the option '--radius=1.2'
///
/// ARGUMENT: command line argument that is not an option, like
/// 'r+a' or 'file1' in the command 'chmod -R r+a file1'
class Arg
{
    public:
    /// @brief ctor
    ///
    /// @param long_name POSIX-style name
    ///
    /// Does not contain the '--' prefix.
    ///
    /// @param short_name Traditional, one character name
    ///
    /// Does not contain the '-' prefix.
    ///
    /// @param description Description
    ///
    /// Description that will be shown in the help.
    ///
    /// @param address Address of the extracted variable
    ///
    /// Address of the extracted variable that will contain
    /// the value that gets extracted from the command line.
    ///
    /// @param flag Indicates if argument allows option arguments
    Arg (const std::string &long_name,
        char short_name,
        const std::string &description,
        const void *address,
        bool flag,
        const std::string &long_arg_name,
        const std::string &short_arg_name);
    /// @brief Access to private data
    ///{
    std::string LongName () const;
    char ShortName () const;
    std::string Description () const;
    const void *Address () const;
    bool Flag () const;
    std::string LongArgName () const;
    std::string ShortArgName () const;
    ///}
    /// @brief Str data functions
    ///
    /// The 'str' data contain the string from the command
    /// line that is associated with this argument.
    std::string GetStr () const;
    void SetStr (const std::string &s);
    private:
    std::string long_name;
    char short_name;
    std::string description;
    const void *address;
    std::string str;
    bool flag;
    std::string long_arg_name;
    std::string short_arg_name;
};

/// @brief CommandLine command line
class CommandLine
{
    public:
    /// @brief Booleans are flags and therefore do not have argument options.
    void AddSpec (const std::string &long_name,
        char short_name,
        const bool &value,
        const std::string &description);
    /// @brief Anything that is not a boolean must specify an argument option.
    template <typename T>
    void AddSpec (const std::string &long_name,
        char short_name,
        const T &value,
        const std::string &description,
        const std::string &long_arg_name = "ARG",
        const std::string &short_arg_name = " ARG")
    {
        args.push_back (
            Arg (long_name, short_name, description,
                static_cast<const void *> (&value), false, long_arg_name, short_arg_name));
    }
    /// @brief Get a usage string
    std::string Usage () const;
    /// @brief Get a help string
    std::string Help (const std::string &indent = "\t", unsigned width = 25) const;
    /// @brief Group command line arguments
    void GroupArgs (int argc, char **argv, int begin = 1, int end = -1);
    /// @brief You must call 'ExtractBegin' before calling 'Extract'
    void ExtractBegin ();

    /// @brief Get an argument from the command line
    template <typename T>
    void Extract (T &value)
    {
        if (arg_map.empty ())
            throw std::runtime_error ("No arguments were found (was ExtractBegin() called?)");
        if (arg_map.find (&value) == arg_map.end ())
            throw std::runtime_error ("The specified value address was not found");
        if (!arg_map[&value]->GetStr ().empty ())
        {
            std::stringstream ss (arg_map[&value]->GetStr ());
            ss >> value;
        }
        arg_map.erase (&value);
    }
    /// @brief You must call 'ExtractEnd' after all calls to 'Extract'
    void ExtractEnd ();
    /// @brief Get any args that were not specified
    std::vector<std::string> GetLeftOverArgs () const;

    private:
    std::vector<Arg> args;
    std::vector<std::string> leftover_args;
    std::map<const void *, const Arg *> arg_map;
    int ProcessArgv (int argc, char **argv, int current_argv, bool *no_more_options);
    void ProcessArg (int argc, char **argv, int current_argv);
    void ProcessLongOpt (int argc, char **argv, int current_argv);
    int ProcessShortOpt (int argc, char **argv, int current_argv);
};

} // namespace horny_toad

#endif // ARGV_H
