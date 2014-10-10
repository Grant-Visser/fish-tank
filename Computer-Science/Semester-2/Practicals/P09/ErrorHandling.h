#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H

class Exception
{

};

class DLLNameExcpetion : public Exception
{
};

class FileManipException : public Exception
{
};

class FileOpeningException : public Exception
{
};

class DLLLoadingException : public Exception
{
};

class FunctionExtractionException : public Exception
{
};

class FunctionInvocationException : public Exception
{
};
#endif
