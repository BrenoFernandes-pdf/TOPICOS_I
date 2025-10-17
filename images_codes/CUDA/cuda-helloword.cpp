// devemos instalar antes o .h do cuda_runtime
// Mas na aula rodamos no site leetGPU

#include <iostream>
#include <cuda_runtime.h>

// Kernel CUDA (executa na GPU)
__global__ void helloFromGPU(){
    int i = threadIdx.x;
    printf("Hello World from GPU!\\n");
    printf("Hello from GPU thread %d\n", i);
}

int main() {
    // Mensagem da CPU
    std::cout << "Hello World from CPU!" << std::endl;

    // Lançar o kernel (1 bloco, 1 thread)
    helloFromGPU<<<1, 5>>>();

    // Esperar o kernel terminar
    cudaDeviceSynchronize();

    return 0;

}