################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/input/Handle_Filenames.cpp \
../source/input/Process_Opt_Data.cpp \
../source/input/Process_Scan_Data.cpp 

OBJS += \
./source/input/Handle_Filenames.o \
./source/input/Process_Opt_Data.o \
./source/input/Process_Scan_Data.o 

CPP_DEPS += \
./source/input/Handle_Filenames.d \
./source/input/Process_Opt_Data.d \
./source/input/Process_Scan_Data.d 


# Each subdirectory must supply rules for building sources it contributes
source/input/%.o: ../source/input/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=gnu++14 -I"X:\workspace\gaussian tools\headers" -O2 -m64 -Wall -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


