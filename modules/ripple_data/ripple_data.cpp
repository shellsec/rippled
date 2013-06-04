//------------------------------------------------------------------------------
/*
	Copyright (c) 2011-2013, OpenCoin, Inc.

	Permission to use, copy, modify, and/or distribute this software for any
	purpose with  or without fee is hereby granted,  provided that the above
	copyright notice and this permission notice appear in all copies.

	THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
	WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES OF
	MERCHANTABILITY  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
	ANY SPECIAL,  DIRECT, INDIRECT,  OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
	WHATSOEVER  RESULTING  FROM LOSS OF USE, DATA OR PROFITS,  WHETHER IN AN
	ACTION OF CONTRACT, NEGLIGENCE  OR OTHER TORTIOUS ACTION, ARISING OUT OF
	OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

/**	Add this to get the @ref ripple_data module.

    @file ripple_data.cpp
    @ingroup ripple_data
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

#include <boost/format.hpp>
#include <boost/functional/hash.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/unordered_map.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>

#include <openssl/ec.h>
#include <openssl/bn.h>
#include <openssl/ecdsa.h>
#include <openssl/pem.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <boost/test/unit_test.hpp>

// VFALCO: TODO, fix these warnings!
#ifdef _MSC_VER
//#pragma warning (push) // Causes spurious C4503 "decorated name exceeds maximum length"
#pragma warning (disable: 4018) // signed/unsigned mismatch
//#pragma warning (disable: 4244) // conversion, possible loss of data
#endif

#include "ripple_data.h"

#include "crypto/ripple_Base58.h" // for RippleAddress
#include "crypto/ripple_CKey.h" // needs RippleAddress VFALCO: TODO, remove this dependency cycle
#include "crypto/ripple_RFC1751.h"

#include "crypto/ripple_CBigNum.cpp"
#include "crypto/ripple_CKey.cpp"
#include "crypto/ripple_CKeyDeterministic.cpp"
#include "crypto/ripple_CKeyECIES.cpp"
#include "crypto/ripple_Base58.cpp"
#include "crypto/ripple_Base58Data.cpp"
#include "crypto/ripple_RFC1751.cpp"

#include "format/ripple_FieldNames.cpp"
#include "format/ripple_LedgerFormat.cpp"
#include "format/ripple_RippleAddress.cpp"
#include "format/ripple_SerializedTypes.cpp"
#include "format/ripple_Serializer.cpp"
#include "format/ripple_SerializedObject.cpp"
#include "format/ripple_TER.cpp"
#include "format/ripple_TransactionFormat.cpp"

// VFALCO: TODO Fix this for SConstruct
#ifdef _MSC_VER
#include "ripple.pb.cc" // BROKEN because of SConstruct
#endif

#ifdef _MSC_VER
//#pragma warning (pop)
#endif
