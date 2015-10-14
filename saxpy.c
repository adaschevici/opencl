#include<stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
    #include<OpenCL/cl.h>
#else
    #include<CL/cl.h>
#endif
#define VECTOR_SIZE 1024

// OpenCL kernel which is run for every work item created
const char *saxpy_kernel = 
"__kernel                                   \n"
"void saxpy_kernel(float alpha,             \n"
"                   __global float *A       \n"
"                   __global float *B       \n"
"                   __global float *C)      \n"
"{                                          \n"
"   // Get the index of the work item       \n"
"   int index = get_global_id(0);           \n"
"   C[index] = alpha * A[index] + B[index]; \n"
"}                                          \n";


int main(int argc, char** argv) {
    int i;
    // Allocate space for vectors A, B and C
    float alpha = 2.0;
    float *A = (float*)malloc(sizeof(float)*VECTOR_SIZE);
    float *B = (float*)malloc(sizeof(float)*VECTOR_SIZE);
    float *C = (float*)malloc(sizeof(float)*VECTOR_SIZE);
    for(i = 0; i < VECTOR_SIZE; i++)
    {
      A[i] = i;
      B[i] = VECTOR_SIZE - i;
      C[i] = 0;
    }
    // Get platform and device information
    cl_platform_id *platforms = NULL;
    cl_uint     num_platforms;
    //Set up the Platform
    cl_int clStatus = clGetPlatformIDs(0, NULL, &num_platforms);
    platforms = (cl_platform_id *)
                malloc(sizeof(cl_platform_id)*num_platforms);
    clStatus = clGetPlatformIDs(num_platforms, platforms, NULL);

    //Get the devices list and choose the device you want to run on
    cl_device_id     *device_list = NULL;
    cl_uint           num_devices;
    printf("%d", num_platforms);
    printf("%d", clStatus);

}
