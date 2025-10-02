#pragma once

#define DEBUG_PRINT(Value) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%s"), *Value->GetClass()->GetName()));

//*Way to use: DEBUG_PRINT("Test: %d", variable)
#define DEBUG_PRINT1(Format, ...) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT(Format), ##__VA_ARGS__) );

#define DEBUG_PRINT2(Name) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("%s"), Name));
