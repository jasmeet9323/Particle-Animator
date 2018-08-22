################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Particle.cpp \
../ParticleAnimation.cpp \
../Screen.cpp \
../Swarm.cpp 

O_SRCS += \
../ParticleAnimation.o 

OBJS += \
./Particle.o \
./ParticleAnimation.o \
./Screen.o \
./Swarm.o 

CPP_DEPS += \
./Particle.d \
./ParticleAnimation.d \
./Screen.d \
./Swarm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/singh/repositories/SDL/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


