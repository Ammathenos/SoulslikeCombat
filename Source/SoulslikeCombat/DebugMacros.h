#pragma once

//#define DEBUG_PRINT(Value) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, *LexToString());

#define DEBUG_PRINT(Format, ...) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT(Format), ##__VA_ARGS__) );