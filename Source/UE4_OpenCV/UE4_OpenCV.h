// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "OpenCV.h"
#include "UCVUMat.h"

#include <opencv2/opencv.hpp>

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

UENUM(BlueprintType)
enum class EMorphShapes : uint8 {
  STREL_ELLIPSE = cv::MorphShapes::MORPH_ELLIPSE UMETA(DisplayName = "Ellipse"),
  STREL_RECT = cv::MorphShapes::MORPH_RECT UMETA(DisplayName = "Rect"),
  STREL_CROSS = cv::MorphShapes::MORPH_CROSS UMETA(DisplayName = "Cross")
};

UENUM(BlueprintType)
enum class EMorphOperation : uint8 {
  DILATE = cv::MorphTypes::MORPH_DILATE UMETA(DisplayName = "Dilate"),
  ERODE = cv::MorphTypes::MORPH_ERODE UMETA(DisplayName = "Erode"),
  OPEN = cv::MorphTypes::MORPH_OPEN UMETA(DisplayName = "Open"),
  CLOSE = cv::MorphTypes::MORPH_CLOSE UMETA(DisplayName = "Close"),
  GRADIENT = cv::MorphTypes::MORPH_GRADIENT UMETA(DisplayName = "Gradient")
};

UCLASS()
class UE4_OpenCV : public UObject {
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable,
            meta = (DisplayName = "Set Scalar", CompactNodeTitle = "=", Keywords = "= set"),
            Category = "OpenCV|ImageProcessing")
  static UCVUMat *set(UCVUMat *dst, FVector4 value) {
    try {
      dst->m = cv::Scalar(value.X, value.Y, value.Z, value.W);
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Clone"), Category = "OpenCV|ImageProcessing")
  static UCVUMat *clone(const UCVUMat *src) {
    auto r = NewObject<UCVUMat>();
    r->m = src->m.clone();
    return r;
  };

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Copy"), Category = "OpenCV|ImageProcessing")
  static UCVUMat *copy(const UCVUMat *src, UCVUMat *dst) {
    try {
      src->m.copyTo(dst->m);
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable,
            meta = (DisplayName = "Add Scalar", CompactNodeTitle = "+",
                    Keywords = "+ add addition"),
            Category = "OpenCV|Arithmetic")
  static UCVUMat *addScalar(UCVUMat *src1, FVector4 scalar, UCVUMat *dst) {
    try {
      cv::add(src1->m, cv::Scalar(scalar.X, scalar.Y, scalar.Z, scalar.W), dst->m);

    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable,
            meta = (DisplayName = "Subtract Scalar", CompactNodeTitle = "-",
                    Keywords = "- sub subtraction"),
            Category = "OpenCV|Arithmetic")
  static UCVUMat *subScalar(UCVUMat *src1, FVector4 scalar, UCVUMat *dst) {
    try {
      cv::subtract(src1->m, cv::Scalar(scalar.X, scalar.Y, scalar.Z, scalar.W), dst->m);

    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable,
            meta = (DisplayName = "Multiply Scalar", CompactNodeTitle = "*",
                    Keywords = "* mul mult multply"),
            Category = "OpenCV|Arithmetic")
  static UCVUMat *mulScalar(UCVUMat *src1, FVector4 scalar, UCVUMat *dst) {
    try {
      cv::multiply(src1->m, cv::Scalar(scalar.X, scalar.Y, scalar.Z, scalar.W), dst->m);

    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable,
            meta = (DisplayName = "Add UMat", CompactNodeTitle = "+", Keywords = "+ add addition"),
            Category = "OpenCV|Arithmetic")
  static UCVUMat *add(UCVUMat *src1, UCVUMat *src2, UCVUMat *dst) {
    try {
      cv::add(src1->m, src2->m, dst->m);
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable,
            meta = (DisplayName = "Subtract UMat", CompactNodeTitle = "-",
                    Keywords = "- sub subtraction"),
            Category = "OpenCV|Arithmetic")
  static UCVUMat *sub(UCVUMat *src1, UCVUMat *src2, UCVUMat *dst) {
    try {
      cv::subtract(src1->m, src2->m, dst->m);
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable,
            meta = (DisplayName = "Multiply UMat", CompactNodeTitle = "*", Keywords = "* mul mult"),
            Category = "OpenCV|Arithmetic")
  static UCVUMat *mul(UCVUMat *src1, UCVUMat *src2, UCVUMat *dst) {
    try {
      cv::multiply(src1->m, src2->m, dst->m);
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Divide UMat", CompactNodeTitle = "/"),
            Category = "OpenCV|Arithmetic")
  static UCVUMat *div(const UCVUMat *src1, const UCVUMat *src2, UCVUMat *dst) {
    try {
      cv::divide(src1->m, src2->m, dst->m);
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable,
            meta = (DisplayName = "Canny Edge Detection", CompactNodeTitle = "Canny"),
            Category = "OpenCV|ImageProcessing")
  static UCVUMat *Canny(const UCVUMat *src, UCVUMat *dst, float threshold1, float threshold2,
                        int apertureSize = 3, bool L2Gradient = false) {
    try {
      cv::Canny(src->m, dst->m, threshold1, threshold2, apertureSize, L2Gradient);
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Erode"), Category = "OpenCV|ImageProcessing")
  static UCVUMat *erode(const UCVUMat *src, UCVUMat *dst, EMorphShapes shape, int32 kernelSize) {
    try {
      auto krnl =
          cv::getStructuringElement(static_cast<int>(shape), cv::Size{kernelSize, kernelSize});
      cv::erode(src->m, dst->m, krnl);
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Dilate"), Category = "OpenCV|ImageProcessing")
  static UCVUMat *dilate(const UCVUMat *src, UCVUMat *dst, EMorphShapes shape, int32 kernelSize) {
    try {
      auto krnl =
          cv::getStructuringElement(static_cast<int>(shape), cv::Size{kernelSize, kernelSize});
      cv::dilate(src->m, dst->m, krnl);
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Morphology Ex"),
            Category = "OpenCV|ImageProcessing")
  static UCVUMat *morphologyEx(const UCVUMat *src, UCVUMat *dst, EMorphOperation op,
                               EMorphShapes shape, int32 kernelSize, int32 iterations) {
    try {
      auto krnl =
          cv::getStructuringElement(static_cast<int>(shape), cv::Size{kernelSize, kernelSize});
      cv::morphologyEx(src->m, dst->m, static_cast<int>(op), krnl, cv::Point(-1, -1), iterations);
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
  };

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Resize"), Category = "OpenCV|ImageProcessing")
  static UCVUMat *resize(
      const UCVUMat *src, UCVUMat *dst, int32 dsizeX, int32 dsizeY, float fx = 0, float fy = 0,
      FCVInterpolationFlags interpolation = FCVInterpolationFlags::INTER_LINEAR) {
    try {
      cv::resize(src->m, dst->m, cv::Size(dsizeX, dsizeY), fx, fy, static_cast<int>(interpolation));
    } catch (cv::Exception &e) {
      UE_LOG(LogTemp, Warning, TEXT("Function %s: Caught OpenCV Exception: %s"), TEXT(__FUNCTION__),
             UTF8_TO_TCHAR(e.what()));
    }
    return dst;
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
