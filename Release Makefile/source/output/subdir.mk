################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/output/PrintOutput_Opt.cpp \
../source/output/PrintOutput_Scan.cpp 

OBJS += \
./source/output/PrintOutput_Opt.o \
./source/output/PrintOutput_Scan.o 

CPP_DEPS += \
./source/output/PrintOutput_Opt.d \
./source/output/PrintOutput_Scan.d 


# Each subdirectory must supply rules for building sources it contributes
source/output/%.o: ../source/output/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=gnu++14 -I"X:\workspace\gaussian tools\headers" -O2 -m64 -Wall -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


