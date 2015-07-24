################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/Print_Output.cpp \
../source/Process_Files.cpp \
../source/main.cpp 

OBJS += \
./source/Print_Output.o \
./source/Process_Files.o \
./source/main.o 

CPP_DEPS += \
./source/Print_Output.d \
./source/Process_Files.d \
./source/main.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Dev\workspace\g09 atom distance\headers" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


