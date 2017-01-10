#-------------------------------------------------
#
# Project created by QtCreator 2017-01-10T09:31:17
#
#-------------------------------------------------
# This Qt prepared shared library compilation of PDFWriter
# expects the following libraries and their include files in place:
#
# - zlib
# - libjpeg
# - libpng
# - libtiff
# - freetype2
#
# The LibAesgm code of PDFWriter is being used.
#
# You can compile the PDFWriter library using QtCreator.
#
# Installation:
# -------------
# Copy the resulting libraries to the place you want them; e.g.
#
# mac/unix
#       <installdir>/lib
#
# windows
#       <installdir>/win32/lib          Release
#       <installdir>/x64/lib            Release
#       <installdir>/win32/libd         Debug
#       <installdir>/x64/libd           Debug
#
# Next, copy the needed headerfiles to
#
# max/unix/windows
#       <installdir>/include/PDFWriter
#
# The headerfiles needed ara all .h files in the PDFWriter
# directory and the LibAesgm directory.
#-------------------------------------------------

# Variables to set for the needed support libraries
win32: MYLIBDIR = c:/devel/libraries
mac: MYLIBDIR = /Users/hans/devel/libraries

QT       -= core gui

TARGET = libpdfwriter
TEMPLATE = lib

INCLUDEPATH += $$PWD/../../LibAesgm

win32: INCLUDEPATH += $$MYLIBDIR/include
win32: INCLUDEPATH += $$MYLIBDIR/include/freetype

contains(QT_ARCH, i386) { # 32bit
    CONFIG(debug, debug|release) {
        win32: LIBS += -L$$MYLIBDIR/32bit/libd
    } else {
        win32: LIBS += -L$$MYLIBDIR/32bit/lib
    }
} else { #64bit
    CONFIG(debug, debug|release) {
        win32: LIBS += -L$$MYLIBDIR/64bit/libd
    } else {
        win32: LIBS += -L$$MYLIBDIR/64bit/lib
    }
}
win32: LIBS += -lzlib -llibjpeg -llibpng -lfreetype271 -llibtiff -lGdi32
DEFINES += LIBPDFWRITER_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../AbstractContentContext.cpp \
    ../AbstractWrittenFont.cpp \
    ../ANSIFontWriter.cpp \
    ../Ascii7Encoding.cpp \
    ../CatalogInformation.cpp \
    ../CFFANSIFontWriter.cpp \
    ../CFFDescendentFontWriter.cpp \
    ../CFFEmbeddedFontWriter.cpp \
    ../CFFFileInput.cpp \
    ../CFFPrimitiveReader.cpp \
    ../CFFPrimitiveWriter.cpp \
    ../CharStringType1Interpreter.cpp \
    ../CharStringType1Tracer.cpp \
    ../CharStringType2Flattener.cpp \
    ../CharStringType2Interpreter.cpp \
    ../CharStringType2Tracer.cpp \
    ../CIDFontWriter.cpp \
    ../CMYKRGBColor.cpp \
    ../DecryptionHelper.cpp \
    ../DescendentFontWriter.cpp \
    ../DictionaryContext.cpp \
    ../DocumentContext.cpp \
    ../EncryptionHelper.cpp \
    ../EncryptionOptions.cpp \
    ../FontDescriptorWriter.cpp \
    ../FreeTypeFaceWrapper.cpp \
    ../FreeTypeOpenTypeWrapper.cpp \
    ../FreeTypeType1Wrapper.cpp \
    ../FreeTypeWrapper.cpp \
    ../GraphicState.cpp \
    ../GraphicStateStack.cpp \
    ../IndirectObjectsReferenceRegistry.cpp \
    ../InfoDictionary.cpp \
    ../InputAscii85DecodeStream.cpp \
    ../InputBufferedStream.cpp \
    ../InputByteArrayStream.cpp \
    ../InputCharStringDecodeStream.cpp \
    ../InputDCTDecodeStream.cpp \
    ../InputFile.cpp \
    ../InputFileStream.cpp \
    ../InputFlateDecodeStream.cpp \
    ../InputLimitedStream.cpp \
    ../InputPFBDecodeStream.cpp \
    ../InputPredictorPNGAverageStream.cpp \
    ../InputPredictorPNGNoneStream.cpp \
    ../InputPredictorPNGOptimumStream.cpp \
    ../InputPredictorPNGPaethStream.cpp \
    ../InputPredictorPNGSubStream.cpp \
    ../InputPredictorPNGUpStream.cpp \
    ../InputPredictorTIFFSubStream.cpp \
    ../InputRC4XcodeStream.cpp \
    ../InputStreamSkipperStream.cpp \
    ../InputStringBufferStream.cpp \
    ../InputStringStream.cpp \
    ../JPEGImageHandler.cpp \
    ../JPEGImageInformation.cpp \
    ../JPEGImageParser.cpp \
    ../Log.cpp \
    ../MD5Generator.cpp \
    ../ObjectsContext.cpp \
    ../OpenTypeFileInput.cpp \
    ../OpenTypePrimitiveReader.cpp \
    ../OutputAESEncodeStream.cpp \
    ../OutputBufferedStream.cpp \
    ../OutputFile.cpp \
    ../OutputFileStream.cpp \
    ../OutputFlateDecodeStream.cpp \
    ../OutputFlateEncodeStream.cpp \
    ../OutputRC4XcodeStream.cpp \
    ../OutputStreamTraits.cpp \
    ../OutputStringBufferStream.cpp \
    ../PageContentContext.cpp \
    ../PageTree.cpp \
    ../ParsedPrimitiveHelper.cpp \
    ../PDFArray.cpp \
    ../PDFArrayIterator.cpp \
    ../PDFBoolean.cpp \
    ../PDFCosArray.cpp \
    ../PDFCosDict.cpp \
    ../PDFDate.cpp \
    ../PDFDictionary.cpp \
    ../PDFDictionaryIterator.cpp \
    ../PDFDocEncoding.cpp \
    ../PDFDocumentCopyingContext.cpp \
    ../PDFDocumentHandler.cpp \
    ../PDFFormXObject.cpp \
    ../PDFHexString.cpp \
    ../PDFImageXObject.cpp \
    ../PDFIndirectObjectReference.cpp \
    ../PDFInteger.cpp \
    ../PDFLiteralString.cpp \
    ../PDFModifiedPage.cpp \
    ../PDFName.cpp \
    ../PDFNull.cpp \
    ../PDFObject.cpp \
    ../PDFObjectParser.cpp \
    ../PDFPage.cpp \
    ../PDFPageInput.cpp \
    ../PDFPageMergingHelper.cpp \
    ../PDFParser.cpp \
    ../PDFParserTokenizer.cpp \
    ../PDFParsingOptions.cpp \
    ../PDFReal.cpp \
    ../PDFRectangle.cpp \
    ../PDFStream.cpp \
    ../PDFStreamInput.cpp \
    ../PDFSymbol.cpp \
    ../PDFTextString.cpp \
    ../PDFTiledPattern.cpp \
    ../PDFUsedFont.cpp \
    ../PDFWriter.cpp \
    ../PFMFileReader.cpp \
    ../PrimitiveObjectsWriter.cpp \
    ../PSBool.cpp \
    ../RC4.cpp \
    ../RefCountObject.cpp \
    ../ResourcesDictionary.cpp \
    ../StandardEncoding.cpp \
    ../StateReader.cpp \
    ../StateWriter.cpp \
    ../TIFFImageHandler.cpp \
    ../TiffUsageParameters.cpp \
    ../TiledPatternContentContext.cpp \
    ../Timer.cpp \
    ../TimersRegistry.cpp \
    ../Trace.cpp \
    ../TrailerInformation.cpp \
    ../TrueTypeANSIFontWriter.cpp \
    ../TrueTypeDescendentFontWriter.cpp \
    ../TrueTypeEmbeddedFontWriter.cpp \
    ../TrueTypePrimitiveWriter.cpp \
    ../Type1Input.cpp \
    ../Type1ToCFFEmbeddedFontWriter.cpp \
    ../Type1ToType2Converter.cpp \
    ../Type2CharStringWriter.cpp \
    ../UnicodeString.cpp \
    ../UppercaseSequance.cpp \
    ../UsedFontsRepository.cpp \
    ../WinAnsiEncoding.cpp \
    ../WrittenFontCFF.cpp \
    ../WrittenFontTrueType.cpp \
    ../XCryptionCommon.cpp \
    ../XObjectContentContext.cpp \
    ../../LibAesgm/aes_modes.c \
    ../../LibAesgm/aes_ni.c \
    ../../LibAesgm/aescrypt.c \
    ../../LibAesgm/aeskey.c \
    ../../LibAesgm/aestab.c

HEADERS +=\
    ../AbstractContentContext.h \
    ../AbstractWrittenFont.h \
    ../AdapterIByteReaderWithPositionToIReadPositionProvider.h \
    ../ANSIFontWriter.h \
    ../Ascii7Encoding.h \
    ../BetweenIncluding.h \
    ../BoxingBase.h \
    ../CatalogInformation.h \
    ../CFFANSIFontWriter.h \
    ../CFFDescendentFontWriter.h \
    ../CFFEmbeddedFontWriter.h \
    ../CFFFileInput.h \
    ../CFFPrimitiveReader.h \
    ../CFFPrimitiveWriter.h \
    ../CharStringDefinitions.h \
    ../CharStringType1Interpreter.h \
    ../CharStringType1Tracer.h \
    ../CharStringType2Flattener.h \
    ../CharStringType2Interpreter.h \
    ../CharStringType2Tracer.h \
    ../CIDFontWriter.h \
    ../CMYKRGBColor.h \
    ../ContainerIterator.h \
    ../DecryptionHelper.h \
    ../DescendentFontWriter.h \
    ../DictionaryContext.h \
    ../DictOperand.h \
    ../DocumentContext.h \
    ../DocumentContextExtenderAdapter.h \
    ../EFontStretch.h \
    ../EHummusImageType.h \
    ../EncryptionHelper.h \
    ../EncryptionOptions.h \
    ../EPDFVersion.h \
    ../EStatusCode.h \
    ../ETokenSeparator.h \
    ../FontDescriptorWriter.h \
    ../FreeTypeFaceWrapper.h \
    ../FreeTypeOpenTypeWrapper.h \
    ../FreeTypeType1Wrapper.h \
    ../FreeTypeWrapper.h \
    ../FSType.h \
    ../GlyphUnicodeMapping.h \
    ../GraphicState.h \
    ../GraphicStateStack.h \
    ../IANSIFontWriterHelper.h \
    ../IByteReader.h \
    ../IByteReaderWithPosition.h \
    ../IByteWriter.h \
    ../IByteWriterWithPosition.h \
    ../IContentContextListener.h \
    ../IDescendentFontWriter.h \
    ../IDocumentContextExtender.h \
    ../IFontDescriptorHelper.h \
    ../IFormEndWritingTask.h \
    ../IFreeTypeFaceExtender.h \
    ../IndirectObjectsReferenceRegistry.h \
    ../InfoDictionary.h \
    ../InputAscii85DecodeStream.h \
    ../InputBufferedStream.h \
    ../InputByteArrayStream.h \
    ../InputCharStringDecodeStream.h \
    ../InputDCTDecodeStream.h \
    ../InputFile.h \
    ../InputFileStream.h \
    ../InputFlateDecodeStream.h \
    ../InputLimitedStream.h \
    ../InputPFBDecodeStream.h \
    ../InputPredictorPNGAverageStream.h \
    ../InputPredictorPNGNoneStream.h \
    ../InputPredictorPNGOptimumStream.h \
    ../InputPredictorPNGPaethStream.h \
    ../InputPredictorPNGSubStream.h \
    ../InputPredictorPNGUpStream.h \
    ../InputPredictorTIFFSubStream.h \
    ../InputRC4XcodeStream.h \
    ../InputStreamSkipperStream.h \
    ../InputStringBufferStream.h \
    ../InputStringStream.h \
    ../IOBasicTypes.h \
    ../IObjectsContextExtender.h \
    ../IPageEndWritingTask.h \
    ../IPDFParserExtender.h \
    ../IReadPositionProvider.h \
    ../IResourceWritingTask.h \
    ../ITiledPatternEndWritingTask.h \
    ../IType1InterpreterImplementation.h \
    ../IType2InterpreterImplementation.h \
    ../IWrittenFont.h \
    ../JPEGImageHandler.h \
    ../JPEGImageInformation.h \
    ../JPEGImageParser.h \
    ../Log.h \
    ../MapIterator.h \
    ../MD5Generator.h \
    ../MyStringBuf.h \
    ../ObjectsBasicTypes.h \
    ../ObjectsContext.h \
    ../ObjectsContextExtenderAdapter.h \
    ../OpenTypeFileInput.h \
    ../OpenTypePrimitiveReader.h \
    ../OutputAESEncodeStream.h \
    ../OutputBufferedStream.h \
    ../OutputFile.h \
    ../OutputFileStream.h \
    ../OutputFlateDecodeStream.h \
    ../OutputFlateEncodeStream.h \
    ../OutputRC4XcodeStream.h \
    ../OutputStreamTraits.h \
    ../OutputStringBufferStream.h \
    ../PageContentContext.h \
    ../PageTree.h \
    ../ParsedPrimitiveHelper.h \
    ../PDFArray.h \
    ../PDFArrayIterator.h \
    ../PDFBoolean.h \
    ../PDFCosArray.h \
    ../PDFCosDict.h \
    ../PDFDate.h \
    ../PDFDictionary.h \
    ../PDFDictionaryIterator.h \
    ../PDFDocEncoding.h \
    ../PDFDocumentCopyingContext.h \
    ../PDFDocumentHandler.h \
    ../PDFEmbedParameterTypes.h \
    ../PDFFormXObject.h \
    ../PDFHexString.h \
    ../PDFImageXObject.h \
    ../PDFIndirectObjectReference.h \
    ../PDFInteger.h \
    ../PDFLiteralString.h \
    ../PDFModifiedPage.h \
    ../PDFName.h \
    ../PDFNull.h \
    ../PDFObject.h \
    ../PDFObjectCast.h \
    ../PDFObjectParser.h \
    ../PDFPage.h \
    ../PDFPageInput.h \
    ../PDFPageMergingHelper.h \
    ../PDFParser.h \
    ../PDFParserTokenizer.h \
    ../PDFParsingOptions.h \
    ../PDFReal.h \
    ../PDFRectangle.h \
    ../PDFStream.h \
    ../PDFStreamInput.h \
    ../PDFSymbol.h \
    ../PDFTextString.h \
    ../PDFTiledPattern.h \
    ../PDFUsedFont.h \
    ../PDFWriter.h \
    ../PFMFileReader.h \
    ../PrimitiveObjectsWriter.h \
    ../ProcsetResourcesConstants.h \
    ../PSBool.h \
    ../RC4.h \
    ../RefCountObject.h \
    ../RefCountPtr.h \
    ../ResourcesDictionary.h \
    ../SafeBufferMacrosDefs.h \
    ../Singleton.h \
    ../SingleValueContainerIterator.h \
    ../StandardEncoding.h \
    ../StateReader.h \
    ../StateWriter.h \
    ../TIFFImageHandler.h \
    ../TiffUsageParameters.h \
    ../TiledPatternContentContext.h \
    ../Timer.h \
    ../TimersRegistry.h \
    ../Trace.h \
    ../TrailerInformation.h \
    ../TrueTypeANSIFontWriter.h \
    ../TrueTypeDescendentFontWriter.h \
    ../TrueTypeEmbeddedFontWriter.h \
    ../TrueTypePrimitiveWriter.h \
    ../Type1Input.h \
    ../Type1ToCFFEmbeddedFontWriter.h \
    ../Type1ToType2Converter.h \
    ../Type2CharStringWriter.h \
    ../UnicodeString.h \
    ../UppercaseSequance.h \
    ../UsedFontsRepository.h \
    ../WinAnsiEncoding.h \
    ../WrittenFontCFF.h \
    ../WrittenFontRepresentation.h \
    ../WrittenFontTrueType.h \
    ../XCryptionCommon.h \
    ../XObjectContentContext.h \
    ../PDFWriterGlobal.h \
    ../../LibAesgm/aes.h \
    ../../LibAesgm/aes_ni.h \
    ../../LibAesgm/aes_via_ace.h \
    ../../LibAesgm/aescpp.h \
    ../../LibAesgm/aesopt.h \
    ../../LibAesgm/aestab.h \
    ../../LibAesgm/brg_endian.h \
    ../../LibAesgm/brg_types.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES +=
