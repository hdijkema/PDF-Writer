/*
   Source File : PDFPage.h


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
#include "PDFRectangle.h"
#include "SingleValueContainerIterator.h"
#include "ResourcesDictionary.h"

#include <list>
#include <utility>

typedef std::pair<bool,PDFRectangle> BoolAndPDFRectangle;
typedef std::pair<bool,unsigned int> BoolAndUnsignedInt;

class PW_EXTERN PageContentContext;

typedef std::list<ObjectIDType> ObjectIDTypeList;

class PW_EXTERN PDFPage
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	PDFPage(void);
	~PDFPage(void);

	void SetMediaBox(const PDFRectangle& inMediaBox);
	const PDFRectangle& GetMediaBox() const;
    
	// sets page rotation factor (optional, must be multiple of 90)
	void SetRotate( unsigned int inRotate );
    // returns indicator for wheather rotation was set, and its value
	const BoolAndUnsignedInt& GetRotate() const;
    
    // crop box, defaults to MediaBox
    // bleed box, defaults to crop box
    // trim box, defaults to crop box
    // art box, default to crop box

	void SetCropBox(const PDFRectangle& inCropBox);
    // returns indicator for wheather crop was set, and its value
	const BoolAndPDFRectangle& GetCropBox() const;

	void SetBleedBox(const PDFRectangle& inBleedBox);
    // returns indicator for wheather crop was set, and its value
	const BoolAndPDFRectangle& GetBleedBox() const;
    
	void SetTrimBox(const PDFRectangle& inTrimBox);
    // returns indicator for wheather crop was set, and its value
	const BoolAndPDFRectangle& GetTrimBox() const;

	void SetArtBox(const PDFRectangle& inArtBox);
    // returns indicator for wheather crop was set, and its value
	const BoolAndPDFRectangle& GetArtBox() const;
    
	ResourcesDictionary& GetResourcesDictionary();

	void AddContentStreamReference(ObjectIDType inStreamReference);
	ObjectIDType GetContentStreamsCount();
	SingleValueContainerIterator<ObjectIDTypeList> GetContentStreamReferencesIterator();

	// extensibility, direct access to the content context used for this page..
	PageContentContext* GetAssociatedContentContext();
	void DisassociateContentContext();
	void AssociateContentContext(PageContentContext* inContentContext);

private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif
	PDFRectangle mMediaBox;
	BoolAndUnsignedInt mRotate;
    BoolAndPDFRectangle mTrimBox;
    BoolAndPDFRectangle mArtBox;
    BoolAndPDFRectangle mCropBox;
    BoolAndPDFRectangle mBleedBox;
	ObjectIDTypeList mContentStreamReferences;
	ResourcesDictionary mResources;
	PageContentContext* mContentContext;

};
