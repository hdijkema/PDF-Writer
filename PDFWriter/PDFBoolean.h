/*
   Source File : PDFBoolean.h


   Copyright 2011 Gal Kahana PDFWriter

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   
*/
#pragma once
#include "PDFWriterGlobal.h"

#include "PDFObject.h"

class PW_EXTERN PDFBoolean : public PDFObject
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif

	enum EType
	{
		eType = ePDFObjectBoolean
	};

	PDFBoolean(bool inValue);
	virtual ~PDFBoolean(void);

	bool GetValue() const;
	operator bool() const;


private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif
	bool mValue;
};
