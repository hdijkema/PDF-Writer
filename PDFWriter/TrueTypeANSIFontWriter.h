/*
   Source File : TrueTypeANSIFontWriter.h


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

#include "EStatusCode.h"
#include "IANSIFontWriterHelper.h"
#include "IFontDescriptorHelper.h"
#include "ObjectsBasicTypes.h"

class PW_EXTERN FreeTypeFaceWrapper;
struct WrittenFontRepresentation;
class PW_EXTERN ObjectsContext;

class PW_EXTERN TrueTypeANSIFontWriter : public IANSIFontWriterHelper, IFontDescriptorHelper
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	TrueTypeANSIFontWriter(void);
	~TrueTypeANSIFontWriter(void);

	PDFHummus::EStatusCode WriteFont(	FreeTypeFaceWrapper& inFontInfo,
							WrittenFontRepresentation* inFontOccurrence,
							ObjectsContext* inObjectsContext,
							bool inEmbedFont);

	// IANSIFontWriterHelper implementation
	virtual void WriteSubTypeValue(DictionaryContext* inDictionary);
	virtual IFontDescriptorHelper* GetCharsetWriter();
	virtual bool CanWriteDifferencesFromWinAnsi();

	// IFontDescriptorHelper implementation
	virtual void WriteCharSet(	DictionaryContext* inDescriptorContext,
								ObjectsContext* inObjectsContext,
								FreeTypeFaceWrapper* inFontInfo,
								const UIntAndGlyphEncodingInfoVector& inEncodedGlyphs);
	virtual void WriteFontFileReference(DictionaryContext* inDescriptorContext,
										ObjectsContext* inObjectsContext);

private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif

	ObjectIDType mEmbeddedFontFileObjectID;
};
