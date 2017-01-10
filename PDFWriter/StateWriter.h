/*
   Source File : StateWriter.h


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
#include "OutputFile.h"
#include "IOBasicTypes.h"
#include "ObjectsBasicTypes.h"

#include <string>



class PW_EXTERN ObjectsContext;

class PW_EXTERN StateWriter
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	StateWriter(void);
	virtual ~StateWriter(void);

	PDFHummus::EStatusCode Start(const std::string& inStateFilePath);
	ObjectsContext* GetObjectsWriter();
	void SetRootObject(ObjectIDType inRootObjectID);
	PDFHummus::EStatusCode Finish();

private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif

	ObjectsContext* mObjectsContext;
	OutputFile mOutputFile;
	ObjectIDType mRootObject;

	void WriteTrailerDictionary();
	void WriteXrefReference(IOBasicTypes::LongFilePositionType inXrefTablePosition);
	void WriteFinalEOF();

};
