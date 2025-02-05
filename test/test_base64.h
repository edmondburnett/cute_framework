/*
	Cute Framework
	Copyright (C) 2019 Randy Gaul https://randygaul.net

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
	   claim that you wrote the original software. If you use this software
	   in a product, an acknowledgment in the product documentation would be
	   appreciated but is not required.
	2. Altered source versions must be plainly marked as such, and must not be
	   misrepresented as being the original software.
	3. This notice may not be removed or altered from any source distribution.
*/

#include <cute_base64.h>
using namespace Cute;

CF_TEST_CASE(test_base64_encode, "Test vectors from RFC 4648.");
int test_base64_encode()
{
	uint8_t buffer[256];

	// Test vectors from: https://tools.ietf.org/html/rfc4648#section-10

	CF_TEST_CHECK(cf_is_error(cf_base64_encode(buffer, 256, "", 0)));

	CF_TEST_CHECK(cf_is_error(cf_base64_encode(buffer, 256, "f", 1)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "Zg==", 4));

	CF_TEST_CHECK(cf_is_error(cf_base64_encode(buffer, 256, "fo", 2)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "Zm8=", 4));

	CF_TEST_CHECK(cf_is_error(cf_base64_encode(buffer, 256, "foo", 3)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "Zm9v", 4));

	CF_TEST_CHECK(cf_is_error(cf_base64_encode(buffer, 256, "foob", 4)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "Zm9vYg==", 8));

	CF_TEST_CHECK(cf_is_error(cf_base64_encode(buffer, 256, "fooba", 5)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "Zm9vYmE=", 8));

	CF_TEST_CHECK(cf_is_error(cf_base64_encode(buffer, 256, "foobar", 6)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "Zm9vYmFy", 8));
	
	CF_TEST_CHECK(cf_is_error(cf_base64_decode(buffer, 256, "", 0)));

	CF_TEST_CHECK(cf_is_error(cf_base64_decode(buffer, 256, "Zg==", 4)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "f", 1));

	CF_TEST_CHECK(cf_is_error(cf_base64_decode(buffer, 256, "Zm8=", 4)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "fo", 2));

	CF_TEST_CHECK(cf_is_error(cf_base64_decode(buffer, 256, "Zm9v", 4)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "foo", 3));

	CF_TEST_CHECK(cf_is_error(cf_base64_decode(buffer, 256, "Zm9vYg==", 8)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "foob", 4));

	CF_TEST_CHECK(cf_is_error(cf_base64_decode(buffer, 256, "Zm9vYmE=", 8)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "fooba", 5));

	CF_TEST_CHECK(cf_is_error(cf_base64_decode(buffer, 256, "Zm9vYmFy", 8)));
	CF_TEST_ASSERT(!CF_MEMCMP(buffer, "foobar", 6));

	// Assert failure on some bad inputs.
	CF_TEST_ASSERT(cf_is_error(cf_base64_decode(buffer, 256, "f===", 4)));
	CF_TEST_ASSERT(cf_is_error(cf_base64_decode(buffer, 256, "foo~", 4)));
	CF_TEST_ASSERT(cf_is_error(cf_base64_decode(buffer, 256, "foo", 3)));
	CF_TEST_ASSERT(cf_is_error(cf_base64_decode(buffer, 256, "\\!@$", 4)));

	CF_TEST_CHECK(cf_is_error(cf_base64_decode(buffer, 256, "zzz=", 4)));

	return 0;
}
