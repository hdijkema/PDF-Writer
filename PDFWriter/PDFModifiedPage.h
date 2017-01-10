/*
   Source File : PDFModifiedPage.h


   Copyright 2013 Gal Kahana PDFWriter

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

#include "EStatusCode.h"
#include "PDFRectangle.h"
#include <vector>
#include <string>

class PW_EXTERN AbstractContentContext;
class PW_EXTERN PDFWriter;
class PW_EXTERN PDFFormXObject;
class PW_EXTERN PDFDictionary;
class PW_EXTERN PDFDocumentCopyingContext;
class PW_EXTERN ObjectsContext;
class PW_EXTERN ResourcesDictionary;
class PW_EXTERN PDFParser;

typedef std::vector<PDFFormXObject*> PDFFormXObjectVector;

#pragma once
#include "PDFWriterGlobal.h"
class PW_EXTERN PDFModifiedPage
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	PDFModifiedPage(PDFWriter* inWriter,unsigned long inPageIndex,bool inEnsureContentEncapsulation = false);
	~PDFModifiedPage(void);

	AbstractContentContext* StartContentContext();
	PDFHummus::EStatusCode PauseContentContext();
	PDFHummus::EStatusCode EndContentContext();
	AbstractContentContext* GetContentContext();


	PDFHummus::EStatusCode AttachURLLinktoCurrentPage(const std::string& inURL, const PDFRectangle& inLinkClickArea);

	PDFHummus::EStatusCode WritePage();


	// advanced
	ResourcesDictionary* GetCurrentResourcesDictionary();
	PDFFormXObject* GetCurrentFormContext();
private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif

	PDFWriter* mWriter;
	unsigned long mPageIndex;
	bool mEnsureContentEncapsulation;
	PDFFormXObject* mCurrentContext;
	PDFFormXObjectVector mContenxts;
	bool mIsDirty;

	std::vector<std::string> WriteModifiedResourcesDict(PDFParser* inParser,PDFDictionary* inResourcesDictionary,ObjectsContext& inObjectContext,PDFDocumentCopyingContext* inCopyingContext);
	unsigned char GetDifferentChar(unsigned char);

};

