
#ifndef ERROR_H
#define ERROR_H

#include <stdint.h>
#include "proto/generated/error.pb.h"

namespace scyna
{
    class Error
    {
    private:
        scyna_proto::Error data_;
        Error(uint32_t code, std::string message)
        {
            data_.set_code(code);
            data_.set_message(message);
        }

    public:
        const scyna_proto::Error &toProto() const
        {
            return data_;
        }

        static Error *New(uint32_t code, std::string message)
        {
            return new Error(code, message);
        }
    };

    const Error *OK = Error::New(0, "Success");
    const Error *SERVER_ERROR = Error::New(1, "Server Error");
    const Error *BAD_REQUEST = Error::New(2, "Bad Request");
    const Error *PERMISSION_ERROR = Error::New(4, "Permission Error");
    const Error *REQUEST_INVALID = Error::New(5, "Request Invalid");
    const Error *MODULE_NOT_EXIST = Error::New(6, "Module Not Exist");
    const Error *BAD_DATA = Error::New(7, "Bad Data");
    const Error *STREAM_ERROR = Error::New(8, "Stream Error");

} // namespace scyna

#endif