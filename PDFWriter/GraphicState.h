/*
   Source File : GraphicState.h


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

#include <string>

class PW_EXTERN PDFUsedFont;

class PW_EXTERN GraphicState
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	GraphicState(void);
	GraphicState(const GraphicState& inGraphicState);
	~GraphicState(void);

	GraphicState& operator=(const GraphicState& inGraphicState);

    PDFUsedFont *getFont();
    void setFont(PDFUsedFont *f);

    double getFontSize();
    void setFontSize(double fs);

    std::string getPlacedFontName();
    void setPlacedFontName(std::string pfn);

    double getPlacedFontSize();
    void setPlacedFontSize(double pfs);


private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif
    // current font properties
	PDFUsedFont* mFont;
	double mFontSize;
	std::string mPlacedFontName;
	double mPlacedFontSize;
};
