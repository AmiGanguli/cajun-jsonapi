/******************************************************************************

This file Copyright (c) 2013 by Ami Ganguli
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright 
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the projecct nor the names of its contributors 
      may be used to endorse or promote products derived from this software 
      without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

#include "json/reader.h"
#include "json/writer.h"
#include "json/elements.h"

#include <sstream>

const char *test_data = 
	"{\n"
	"	\"start\"		: 1366147777,\n"
	"	\"end\"			: 1367147777,\n"
	"	\"quanta duration\"	: 900,\n"
	"	\"generators\"	:\n"
	"	[\n"
	"		{\n"
	"			\"op\"			: \"add\",\n"
	"			\"type\"		: \"cron\",\n"
	"			\"minutes\"		: \"*\",\n"
	"			\"hours\"		: \"*\",\n"
	"			\"day of month\"	: \"*\",\n"
	"			\"day of week\"		: \"*\",\n"
	"			\"year\"		: \"*\"\n"
	"		}\n"
	"	]\n"
	"}\n"
	;

int 
main()
{
	std::istringstream data(test_data);
	json::Object doc;
	try {
		json::Reader::Read(doc, data);
	} catch (json::Reader::ParseException& e) {
		std::cout << "Caught json::ParseException: " 
		          << e.what() << ", Line/offset: " 
		          << e.m_locTokenBegin.m_nLine + 1
		          << '/' << e.m_locTokenBegin.m_nLineOffset + 1 
		          << std::endl << std::endl;
	}

	json::Writer::Write(doc, std::cout);
	std::cout << std::endl;

	return 0;
}
