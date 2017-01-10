/*
   Source File : PDFFormXObject.h


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

#include "ObjectsBasicTypes.h"
#include "ResourcesDictionary.h"


namespace PDFHummus
{
	class PW_EXTERN DocumentContext;
};

class PW_EXTERN PDFStream;
class PW_EXTERN XObjectContentContext;
class PW_EXTERN ObjectsContext;

class PW_EXTERN PDFFormXObject
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif

	PDFFormXObject(PDFHummus::DocumentContext* inDocumentContext,ObjectIDType inFormXObjectID,PDFStream* inXObjectStream,ObjectIDType inFormXObjectResourcesDictionaryID);
	~PDFFormXObject(void);

	ObjectIDType GetObjectID();
	ObjectIDType GetResourcesDictionaryObjectID();

	ResourcesDictionary& GetResourcesDictionary();
	XObjectContentContext* GetContentContext();
	PDFStream* GetContentStream();

	
private:
#ifdef _MSC_VER
#	pragma warning(disable:4251)
#endif

	ObjectIDType mXObjectID;
	ObjectIDType mResourcesDictionaryID;
	ResourcesDictionary mResources;
	PDFStream* mContentStream;
	XObjectContentContext* mContentContext;
};
