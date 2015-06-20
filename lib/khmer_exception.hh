//
// This file is part of khmer, https://github.com/dib-lab/khmer/, and is
// Copyright (C) Michigan State University, 2009-2015. It is licensed under
// the three-clause BSD license; see LICENSE.
// Contact: khmer-project@idyll.org
//

#ifndef KHMER_EXCEPTION_HH
#define KHMER_EXCEPTION_HH

#include <exception>
#include <string>

namespace khmer
{

///
// A base class for all exceptions.
//
// All exceptions should be derived from this base class or a sub-class
//
class khmer_exception : public std::exception
{
public:
    explicit khmer_exception(const std::string& msg = "Generic khmer exception")
        : _msg(msg) { }

    virtual ~khmer_exception() throw() { }
    virtual const char* what() const throw ()
    {
        return _msg.c_str();
    }

protected:
    const std::string _msg;
};


/////// Base Exceptions /////

///
// A base class for file exceptions.
//
class khmer_file_exception : public khmer_exception
{
public:
    explicit khmer_file_exception(const std::string& msg)
        : khmer_exception(msg) { }
};

// A base exception for value exceptions
class khmer_value_exception : public khmer_exception
{
public:
    explicit khmer_value_exception(const std::string& msg)
        : khmer_exception(msg) { }
};

/////// Specialised Exceptions /////

class InvalidStream : public khmer_file_exception
{
public:
    InvalidStream()
        : khmer_file_exception("Generic InvalidStream error") {}
    explicit InvalidStream(const std::string& msg)
        : khmer_file_exception(msg) {}
};

class StreamReadError : public khmer_file_exception
{
public:
    StreamReadError()
        : khmer_file_exception("Generic StreamReadError error") {}
    explicit StreamReadError(const std::string& msg)
        : khmer_file_exception(msg) {}
};


///
// An exception for invalid arguments to functions
//

class InvalidValue : public khmer_value_exception
{
public:
    explicit InvalidValue(const std::string& msg)
        : khmer_value_exception(msg) { }
};

///
// An exception for trying to change a read-only attributes
//

class ReadOnlyAttribute : public khmer_exception
{
public:
    explicit ReadOnlyAttribute(const std::string& msg)
        : khmer_exception(msg) { }
};

} // end namespace khmer

#endif // KHMER_EXCEPTION_HH

// vim: set sts=2 sw=2:
