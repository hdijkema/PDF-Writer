#ifndef PDFWRITERGLOBAL_H
#define PDFWRITERGLOBAL_H

#ifdef _WIN32
#  if defined(LIBPDFWRITER_LIBRARY)
#     define PW_EXTERN __declspec(dllexport)
#  else
#     define PW_EXTERN __declspec(dllimport)
#  endif
#else
#  define PW_EXTERN
#endif

#ifdef _MSC_VER
#pragma warning(disable:4100)
#endif

#endif // PDFWRITERGLOBAL_H
