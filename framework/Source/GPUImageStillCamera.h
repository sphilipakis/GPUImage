#import "GPUImageVideoCamera.h"

void stillImageDataReleaseCallback(void *releaseRefCon, const void *baseAddress);
void GPUImageCreateResizedSampleBuffer(CVPixelBufferRef cameraFrame, CGSize finalSize, CMSampleBufferRef *sampleBuffer);

// FROM SPS -->
UIImage* imageFromSampleBuffer(CMSampleBufferRef nextBuffer);
// <-- FROM SPS

@interface GPUImageStillCamera : GPUImageVideoCamera

// Photography controls
- (void)capturePhotoAsSampleBufferWithCompletionHandler:(void (^)(CMSampleBufferRef imageSampleBuffer, NSError *error))block;
- (void)capturePhotoAsImageProcessedUpToFilter:(GPUImageOutput<GPUImageInput> *)finalFilterInChain withCompletionHandler:(void (^)(UIImage *processedImage, NSError *error))block;
- (void)capturePhotoAsJPEGProcessedUpToFilter:(GPUImageOutput<GPUImageInput> *)finalFilterInChain withCompletionHandler:(void (^)(NSData *processedJPEG, NSError *error))block;
- (void)capturePhotoAsPNGProcessedUpToFilter:(GPUImageOutput<GPUImageInput> *)finalFilterInChain withCompletionHandler:(void (^)(NSData *processedPNG, NSError *error))block;

// FROM SPS -->
-(void) capturePhotoAsImageWithCompletionHandler:(void (^)(UIImage *processedImage, NSError *error))block;
// <-- FROM SPS

//Kentoy
- (AVCaptureStillImageOutput*)getAVCaptureStillImageOutput;

@end
