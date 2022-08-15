
#include <codecvt>
#include <locale>
#include <iostream>
#include <string.h>

#include "public/fpdf_doc.h"
#include "public/fpdfview.h"
#include "public/fpdf_edit.h"
#include "public/fpdf_text.h"

#include "pdfdocument.h"
#include "PDFUtil.h"

//#include "fpdf_stringhelper.h"

//#include "converter.h"
int main(int argc, char *argv[])
{
//    constexpr unsigned char kExpectedChanging[] =
//          "\xBC\x37\x29\x8A\x3F\x87\xF4\x79\x22\x9B\xCE\x99\x7C\xA7\x91\xF7";
//    int len = sizeof(kExpectedChanging)/sizeof (char)           ;
//    printf("kExpectedChaing len: %d\n", len);
//    for(int i=0;i<len;i++) {
//      printf("%hX\n", kExpectedChanging[i]);
//    }
//    const char *path = "/home/weikano/文档/需要的文件/书籍/TaggedPDFBestPracticeGuideSyntax.pdf";
//    const char *path = "/home/weikano/git/pdfium/testing/resources/annotation_highlight_long_content(复件).pdf";
//    const char *path = "/home/roman/git/pdfium/testing/resources/annotation_markup_multiline_no_ap.pdf";
///

//    const char *path="/home/roman/文档/文字文稿1.pdf";
//    const char *path = "/home/roman/文档/文字文稿1（复件）（复件）.pdf";
//    const char *path = "/home/weikano/文档/文字文稿1(复件).pdf";
//    const char *path = "/home/roman/文档/test.pdf";
    const char *path = "/home/weikano/git/pdfium/testing/resources/hello_world.pdf";




//    quadpoint :0 (135.559601,750.291016,152.339096,750.291016,152.339096,758.023987,135.559601,758.023987)

//    std::string msg = "2019年4月24日，问天舱和梦天舱完成了初样舱体结构生产，在开展总装工作。2020年5月5日，中国载人空间站工程研制的长征五号B运载火箭，搭载新一代载人飞船试验船和柔性充气式货物返回舱试验舱，在文昌航天发射场点火升空将载荷组合体成功送入预定轨道，首飞任务取得圆满成功，实现空间站阶段飞行任务首战告捷，拉开中国载人航天工程“第三步”任务序幕。中国空间站核心舱已完成正样产品总装，问天实验舱和梦天实验舱在开展初样研制。2022年6月4日，在神舟十四号载人飞行任务新闻发布会上，中国载人航天工程新闻发言人、中国载人航天工程办公室副主任林西强介绍，神舟十四号载人飞行任务主要目的为：配合问天实验舱、梦天实验舱与核心舱的交会对接和转位，完成中国空间站在轨组装建造。2022年7月，梦天实验舱完成正样热试验。            2022年8月9日，据中国载人航天办公室介绍，梦天实验舱已完成出厂前所有研制工作，已运抵文昌航天发射场。后续，梦天实验舱将按计划开展发射场区各项总装和测试工作。 [7]  预计在2022年10月，中国将发射梦天实验舱与核心舱对接，之后空间站三舱形成“T”字基本构型，完成中国空间站在轨建造";
    std::string savePath = "/home/weikano/文档/test.pdf";
    std::string msg = "问天舱和梦天舱完成了初样舱体结构生产";
    std::string msg2 = "jhahdsh\nfasdfasdfsad\nadsf";
    FPDF_InitLibrary();
    std::vector<FS_RECTF> lines;
    PDFDocument *doc = new PDFDocument(path, NULL);
    doc->setSavePath(savePath.c_str());
    int pageIndex = 0;
    int start = 0;
    int end = 3;
    doc->addAnnotations(start,end, msg);
    delete doc;

    std::vector<const IReaderNote*> notes;
    PDFDocument *test = new PDFDocument(savePath.c_str(), nullptr);
    test->listIReaderAnnotations(0, notes);
    test->walkAnnotations();
    std::cout<<"======begin all ireadernotes" <<std::endl;
    for(const IReaderNote* note : notes)
    {
        std::cout<<*note;
    }
    std::cout<<"======end all ireadernotes" << std::endl;
//    test->walkAnnotations();

    delete test;

    FPDF_DestroyLibrary();

    for(const auto line : lines)
    {
        printf("line(%f, %f, %f, %f)\n", line.left, line.top, line.bottom, line.right);
    }


//    int utf_len = PDFUtil::utf8_length(msg.c_str(), msg.length());
//    printf("utf_len :%d\n", utf_len);
//    unsigned short wmsg[utf_len];
//    int len = PDFUtil::utf8_to_ucs2(wmsg, utf_len, msg.c_str(), -1);
//    wmsg[len] = '\0';

//    std::string out;
//    PDFUtil::ucs2_chars_to_string(out, len, wmsg);
//    printf("%s\n", out.c_str());

    return 0;
}
