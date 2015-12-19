################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/calc/DihedralAngle_v1.cpp \
../source/calc/DihedralAngle_v2.cpp \
../source/calc/Normalize_Vector.cpp \
../source/calc/Pythagoras3D.cpp \
../source/calc/ValenceAngle.cpp 

OBJS += \
./source/calc/DihedralAngle_v1.o \
./source/calc/DihedralAngle_v2.o \
./source/calc/Normalize_Vector.o \
./source/calc/Pythagoras3D.o \
./source/calc/ValenceAngle.o 

CPP_DEPS += \
./source/calc/DihedralAngle_v1.d \
./source/calc/DihedralAngle_v2.d \
./source/calc/Normalize_Vector.d \
./source/calc/Pythagoras3D.d \
./source/calc/ValenceAngle.d 


# Each subdirectory must supply rules for building sources it contributes
source/calc/%.o: ../source/calc/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"X:\workspace\gaussian tools\headers" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


