// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "OpenCV.h"
#include "UCVUMat.h"

#include <opencv2/imgproc.hpp>

#include "UE4_OpenCV.generated.h"

UENUM(BlueprintType)  //"BlueprintType" is essential to include
enum class FCVInterpolationFlags : uint8 {
  INTER_NEAREST = 0 UMETA(DisplayName = "Nearest"),
  INTER_LINEAR = 1 UMETA(DisplayName = "Linear"),
  INTER_CUBIC = 2 UMETA(DisplayName = "Cubic"),
  INTER_AREA = 3 UMETA(DisplayName = "Area"),
  INTER_LANCZOS4 = 4 UMETA(DisplayName = "Lanczos4"),
  INTER_LINEAR_EXACT = 5 UMETA(DisplayName = "Linear Exact"),
  INTER_MAX = 7 UMETA(DisplayName = "Max"),
  WARP_FILL_OUTLIERS = 8 UMETA(DisplayName = "Warp Fill Outliers"),
  WARP_INVERSE_MAP = 16 UMETA(DisplayName = "Warp Inverse Map")
};

UCLASS()
class UE4_OpenCV : public UObject {
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Bilateral Filter"),
            Category = "OpenCV|ImageProcessing")
  static void Canny(const UCVUMat *src, UCVUMat *dst, int32 d, float sigmaColor,
                    float sigmaSpace){};

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Erode"), Category = "OpenCV|ImageProcessing")
  static void erode(const UCVUMat *src, UCVUMat *dst, int32 d, float sigmaColor,
                    float sigmaSpace){};

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Dilate"), Category = "OpenCV|ImageProcessing")
  static void dilate(const UCVUMat *src, UCVUMat *dst, int32 d, float sigmaColor,
                     float sigmaSpace){};

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Morphology Ex"),
            Category = "OpenCV|ImageProcessing")
  static void morphologyEx(const UCVUMat *src, UCVUMat *dst, int32 d, float sigmaColor,
                           float sigmaSpace){};

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Resize"), Category = "OpenCV|ImageProcessing")
  static void resize(const UCVUMat *src, UCVUMat *dst, int32 dsizeX, int32 dsizeY, float fx = 0,
                     float fy = 0,
                     FCVInterpolationFlags interpolation = FCVInterpolationFlags::INTER_LINEAR) {
    try {
      cv::resize(src->m, dst->m, cv::Size(dsizeX, dsizeY), fx, fy, static_cast<int>(interpolation));
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Caught OpenCV Exception: %s"), UTF8_TO_TCHAR(e.what()));
    }
  };

  // UFUNCTION(BlueprintCallable, meta = (DisplayName = "Warp Affine"), Category
  // = "OpenCV|ImageProcessing") 	static void warpAffine(const UCVUMat*
  // src,
  // UCVUMat*dst, const UCVUMat* M, int dsizeX, int dsizeY,
  // FCVInterpolationFlags flags = FCVInterpolationFlags::INTER_LINEAR,
  // int borderMode = 0
  ///*cv::BORDER_CONSTANT*/, 		FVector4 borderValue = FVector(0.f));
  //
  //	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Warp Perspective"),
  // Category = "OpenCV|ImageProcessing") 	static void
  // warpPerspective(InputArray
  // src, OutputArray dst, 		InputArray M, Size dsize,
  // int flags
  // =
  // INTER_LINEAR, 		int borderMode = BORDER_CONSTANT,
  // const Scalar& borderValue = Scalar());
};
