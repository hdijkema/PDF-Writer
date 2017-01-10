/*
   Source File : PDFDictionary.h


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
#include "PDFName.h"
#include "MapIterator.h"

#include <map>



class PW_EXTERN PDFNameLess : public std::binary_function<const PDFName*,const PDFName*,bool>
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	bool operator( ) (const PDFName* left, 
						const PDFName* right ) const
	{
		return left->GetValue() < right->GetValue();
	}
};

typedef std::map<PDFName*,PDFObject*,PDFNameLess> PDFNameToPDFObjectMap;

class PW_EXTERN PDFDictionary : public PDFObject
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif

	enum EType
	{
		eType = ePDFObjectDictionary
	};

	PDFDictionary(void);
	virtual ~PDFDictionary(void);

	// AddRefs on both
	void Insert(PDFName* inKeyObject, PDFObject* inValueObject);

    bool Exists(std::string inName);
	PDFObject* QueryDirectObject(std::string inName);

	MapIterator<PDFNameToPDFObjectMap> GetIterator();

private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif

	PDFNameToPDFObjectMap mValues;
};
