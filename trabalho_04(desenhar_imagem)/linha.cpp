#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "headers/stb_image.h"
#include "headers/stb_image_write.h"
#include <iostream>
#include <vector>

struct cor
{
    unsigned char R;
    unsigned char G;
    unsigned char B;

    cor(unsigned char r, unsigned char g, unsigned char b) : R(r), G(g), B(b) {}
};

struct ponto
{
    float x;
    float y;

    ponto(float x0, float y0) : x(x0), y(y0) {}
};

bool compara_pontos(float xi, float xf, float x)
{
    if (xi > xf)
    {
        if (x < xf)
            return false;
        else
            return true;
    }
    else
    {
        if (x > xf)
            return false;
        else
            return true;
    }
}

std::vector<unsigned char> fazer_linha(std::vector<unsigned char> &imagem, int largura, int altura, int canais, cor linha, ponto inicial, ponto final)
{
    inicial.y = -inicial.y;
    final.y = -final.y;
    inicial.x += ((float)largura) / 2;
    final.x += ((float)largura) / 2;
    inicial.y += ((float)altura) / 2;
    final.y += ((float)altura) / 2;

    float a = (final.y - inicial.y) / (final.x - inicial.x);
    float b = inicial.y - a * inicial.x;

    for (int x = inicial.x; compara_pontos(inicial.x, final.x, x); x += inicial.x > final.x ? -1 : 1)
    {
        for (int y = inicial.y; compara_pontos(inicial.y, final.y, y); y += inicial.y > final.y ? -1 : 1)
        {
            int indice = ((y * largura + x) * canais);
            if (y == (int)(a * x + b))
            {
                imagem[indice] = linha.R;
                imagem[indice + 1] = linha.G;
                imagem[indice + 2] = linha.B;
            }
        }
    }

    return imagem;
}

std::vector<unsigned char> fazer_circulo(std::vector<unsigned char> &imagem, int largura, int altura, int canais, cor linha, ponto centro, int raio)
{
    // 1. Converte as coordenadas do centro
    centro.y = -centro.y;
    centro.x += ((float)largura) / 2;
    centro.y += ((float)altura) / 2;

    // 2. Define um "retângulo" (bounding box) ao redor do círculo para testar os pixels
    int x_min = centro.x - raio;
    int x_max = centro.x + raio;
    int y_min = centro.y - raio;
    int y_max = centro.y + raio;

    // 3. Itera sobre cada pixel dentro desse retângulo
    for (int y = y_min; y <= y_max; y++)
    {
        for (int x = x_min; x <= x_max; x++)
        {

            // 4. Calcula a distância do pixel (x,y) atual até o centro do círculo
            // Dist = sqrt((x - centro.x)^2 + (y - centro.y)^2)
            float distancia = std::sqrt(std::pow(x - centro.x, 2) + std::pow(y - centro.y, 2));

            // 5. Se a distância for muito próxima do raio, desenha o pixel
            // Usamos "< 1.0" para dar uma pequena "espessura" à linha do círculo
            if (std::abs(distancia - raio) < 1.0)
            {

                int indice = ((y * largura + x) * canais);

                // Checagem de segurança para não desenhar fora da imagem
                if (indice >= 0 && (indice + 2) < imagem.size())
                {
                    imagem[indice] = linha.R;
                    imagem[indice + 1] = linha.G;
                    imagem[indice + 2] = linha.B;
                }
            }
        }
    }

    return imagem;
}


void fazer_semicirculo(std::vector<unsigned char>& imagem, int largura, int altura, int canais, 
                       cor linha, ponto centro, int raio, bool paraBaixo)
{
    // 1. Converte as coordenadas do centro
    centro.y = -centro.y;
    centro.x += ((float)largura) / 2;
    centro.y += ((float)altura) / 2;

    // 2. Define um "retângulo" (bounding box) ao redor do círculo
    int x_min = centro.x - raio;
    int x_max = centro.x + raio;
    int y_min = centro.y - raio;
    int y_max = centro.y + raio;

    // 3. Itera sobre cada pixel dentro desse retângulo
    for (int y = y_min; y <= y_max; y++) {
        for (int x = x_min; x <= x_max; x++) {
            
            // 4. Calcula a distância do pixel (x,y) atual até o centro
            float distancia = std::sqrt(std::pow(x - centro.x, 2) + std::pow(y - centro.y, 2));

            // 5. Verifica se o pixel está na borda do círculo
            if (std::abs(distancia - raio) < 1.0) {
                
                // Verifica se está na metade correta!
                
                bool desenhar = false;
                if (paraBaixo && y >= centro.y) { // Se for para baixo, desenha pixels com Y maior ou igual ao centro
                    desenhar = true;
                } else if (!paraBaixo && y <= centro.y) { // Se for para cima, desenha pixels com Y menor ou igual
                    desenhar = true;
                }

                if (desenhar) {
                    int indice = ((y * largura + x) * canais);
                    // Checagem de segurança
                    if (indice >= 0 && (indice + 2) < imagem.size()) {
                        imagem[indice] = linha.R;
                        imagem[indice + 1] = linha.G;
                        imagem[indice + 2] = linha.B;
                    }
                }
            }
        }
    }
}

int main()
{

    int largura = 1280;
    int altura = 720;
    int canais = 3;

    std::vector<unsigned char> imagem(largura * altura * canais, 0);
    // Fazer boca
    // Fazer sobrancelhas (como antes)
    fazer_linha(imagem, largura, altura, canais, cor(0, 255, 0), ponto(-50, 100), ponto(-150, 150));
    fazer_linha(imagem, largura, altura, canais, cor(0, 255, 0), ponto(50, 100), ponto(150, 150)); 

    // Fazer olhos (como antes)
    fazer_circulo(imagem, largura, altura, canais, cor(0, 255, 0), ponto(-100, 0), 30);
    fazer_circulo(imagem, largura, altura, canais, cor(0, 255, 0), ponto(100, 0), 30);
    fazer_circulo(imagem, largura, altura, canais, cor(0, 255, 0), ponto(-110, 0), 15);
    fazer_circulo(imagem, largura, altura, canais, cor(0, 255, 0), ponto(110, 0), 15);  
    
    // Parte vertical do nariz
    fazer_linha(imagem, largura, altura, canais, cor(0, 255, 0), ponto(-50, -80), ponto(0, -100));
    // Parte horizontal do nariz (indo para a direita)
    fazer_linha(imagem, largura, altura, canais, cor(0, 255, 0), ponto(-50, -80), ponto(0, -80));

    // --- NOVA BOCA (Formato ':D') ---
    // Parte reta do 'D'
    fazer_linha(imagem, largura, altura, canais, cor(0, 255, 0), ponto(-150, -150), ponto(150, -150));
    // Parte curva do 'D' (um semicírculo para baixo)
    fazer_semicirculo(imagem, largura, altura, canais, cor(255, 0, 0), ponto(0, -150), 100, true);
    fazer_circulo(imagem, largura, altura, canais, cor(255, 255, 0), ponto(0, 0), 300);

    
    // Salvar o resultado final
    stbi_write_png("imagens/rosto_final.png", largura, altura, canais, imagem.data(), 0);
    
    return 0;

    // --- FIM DAS NOVAS COORDENADAS ---
}