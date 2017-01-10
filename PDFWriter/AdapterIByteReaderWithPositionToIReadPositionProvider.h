/*
   Source File : AdapterIByteReaderWithPositionToIReadPositionProvider.h


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

#include "IReadPositionProvider.h"
#include "IByteReaderWithPosition.h"

class PW_EXTERN AdapterIByteReaderWithPositionToIReadPositionProvider : public IReadPositionProvider
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	AdapterIByteReaderWithPositionToIReadPositionProvider(){mStream = NULL;}
	AdapterIByteReaderWithPositionToIReadPositionProvider(IByteReaderWithPosition* inStream){mStream = inStream;}
	
	void Assign(IByteReaderWithPosition* inStream){mStream = inStream;}

	// IReadPositionProvider implementation
	virtual IOBasicTypes::LongFilePositionType GetCurrentPosition(){return mStream->GetCurrentPosition();};

private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif
	IByteReaderWithPosition* mStream;
	
};