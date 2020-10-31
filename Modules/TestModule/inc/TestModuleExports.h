#pragma once

#   if __GNUC__ >= 4
#       define TEST_MODULE_API            __attribute__ ((visibility ("default")))
#       define TEST_MODULE_NOT_EXPORTED   __attribute__ ((visibility ("hidden")))
#       define TEST_MODULE_EXTERN         
#   else
#       define TEST_MODULE_API
#       define TEST_MODULE_NOT_EXPORTED
#       define TEST_MODULE_EXTERN         extern
#   endif