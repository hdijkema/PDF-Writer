/*
   Source File : CIDFontWriter.h


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
#include "WrittenFontRepresentation.h"
#include "ObjectsBasicTypes.h"

#include <utility>
#include <vector>

class PW_EXTERN FreeTypeFaceWrapper;
class PW_EXTERN ObjectsContext;
class PW_EXTERN DictionaryContext;
class PW_EXTERN IDescendentFontWriter;
class PW_EXTERN IByteWriter;



typedef std::pair<unsigned int, GlyphEncodingInfo> UIntAndGlyphEncodingInfo;
typedef std::vector<UIntAndGlyphEncodingInfo> UIntAndGlyphEncodingInfoVector;

class PW_EXTERN CIDFontWriter
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	CIDFontWriter(void);
	virtual ~CIDFontWriter(void);

	PDFHummus::EStatusCode WriteFont(	FreeTypeFaceWrapper& inFontInfo,
							WrittenFontRepresentation* inFontOccurrence,
							ObjectsContext* inObjectsContext,
							IDescendentFontWriter* inDescendentFontWriter,
							bool inEmbedFont);

private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif

	FreeTypeFaceWrapper* mFontInfo;
	WrittenFontRepresentation* mFontOccurrence;
	ObjectsContext* mObjectsContext;
	UIntAndGlyphEncodingInfoVector mCharactersVector;


	void WriteEncoding(DictionaryContext* inFontContext);
	void CalculateCharacterEncodingArray();
	void WriteToUnicodeMap(ObjectIDType inToUnicodeMap);
	void WriteGlyphEntry(IByteWriter* inWriter,unsigned short inEncodedCharacter,const ULongVector& inUnicodeValues);

};
