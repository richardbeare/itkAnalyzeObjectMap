#include "itkRGBPixel.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkAnalyzeObjectMap.h"
#include "itkAnalyzeObjectLabelMapImageIOFactory.h"


typedef unsigned char PixelType;
const unsigned int Dimension = 3;
typedef itk::Image< PixelType, Dimension > ImageType;
typedef itk::ImageFileReader< ImageType > ReaderType;
typedef itk::RGBPixel<PixelType> RGBPixelType;
typedef itk::Image< RGBPixelType, Dimension > RGBImageType;
typedef itk::ImageFileWriter<ImageType> WriterType;
int main(int argc, char * argv [] )
{
  if(argc != 3)
  {
    std::cerr << "USAGE: " << argv[0] << "<inputFileName> <outputFileName>" << std::endl;
  }
  const char *DisplayImage = argv[1];

  itk::ObjectFactoryBase::RegisterFactory( itk::AnalyzeObjectLabelMapImageIOFactory::New() );

  ReaderType::Pointer reader  = ReaderType::New();

  //The input should be an Anaylze Object Map file
  reader->SetFileName( DisplayImage );
  reader->Update();
  
  WriterType::Pointer writer = WriterType::New();
  writer->SetInput(reader->GetOutput());
  writer->SetFileName(argv[2]);
  writer->Update();
}
