// tentar fazer matrizes para a próxima aula na Sexta!!!

#include <iostream>
#include <cuda_runtime.h>

// Kernel executado GPU
__global__ void somaVetores(int *a, int *b, int *c, int N){
    int i = threadIdx.x;
    if(i < N){
        c[i] = a[i] + b[i];
    }
}



int main() {
    const int N = 10;
    int h_a[N], h_b[N], h_c[N];     // vetores na CPU (Host)
    int *d_a, *d_b, *d_c;           // vetores na GPU(Device)

    // 1 - Inicializa vetores na CPU
    for(int i = 0; i < N; i++){
        h_a[i] = i + 1;    // 1, 2, 3, ...
        h_b[i] = (i + 1) * 10; // 10, 20, 30, ...
    }

    // 2 - Aloca memória na GPU
    cudaMalloc(&d_a, N * sizeof(int));
    cudaMalloc(&d_b, N * sizeof(int));
    cudaMalloc(&d_c, N * sizeof(int));


    // 3 - Copia dados CPU -> GPU
    cudaMemcpy(d_a, h_a, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, N * sizeof(int), cudaMemcpyHostToDevice);

    // 4 - Executa o kernel
    somaVetores<<<1, N>>>(d_a, d_b, d_c, N);
    cudaDeviceSynchronize();

    // 5 - Copia resultado GPU -> CPU
    cudaMemcpy(h_c, d_c, N * sizeof(int), cudaMemcpyDeviceToHost);

    // 6 - Exibe resultado
    std::cout << "Resultado da soma: ";
    for (int i = 0; i < N; i++){
        std::cout << h_c[i] << " ";
    }
    std::cout << std::endl;


    // 7 - Libera memória da GPU
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}