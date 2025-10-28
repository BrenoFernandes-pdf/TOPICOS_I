#include <iostream>
#include <string>

int num_aluno = 0; // global para contar aluno (dever haver uma forma mais eficente)

class Escola
{
public:
    std::string nome;
    // construtores Padrão e Parametrizado (Sobrecarga de construtores)
    Escola()
    {
        this->nome = "Sem nome";
    }

    Escola(std::string nome)
    {
        this->nome = nome;
        mostrarEscola();
    }

    class Turma
    {
    public:
        std::string serie;

        Turma()
        {
            this->serie = "Nenhuma série selecionada";
        }

        Turma(std::string serie)
        {
            this->serie = serie;
            mostrarTurma();
        }

        class Aluno
        {
        public:
            std::string nomeAluno;
            double nota;

            Aluno()
            {
                this->nomeAluno = "Sem Nome";
                this->nota = 0;
            }

            Aluno(std::string nomeAluno, double nota)
            {
                this->nomeAluno = nomeAluno;
                this->nota = nota;
                num_aluno++;
                mostrarAluno();
            }

            // Sobrecarga do Operador +: média de notas
            Aluno operator+(Aluno b)
            {
                return Aluno(nomeAluno + "+" + b.nomeAluno, (nota + b.nota) / 2);
            }

            // Declaração da função amiga
            friend std::ostream &operator<<(std::ostream &os, Aluno x)
            {
                os << "Aluno " << num_aluno
                   << " (média) -> Nome: " << x.nomeAluno
                   << ", Nota: " << x.nota << "\n";
                return os;
            }

            void mostrarAluno();
        };

        void mostrarTurma();
    };

    void mostrarEscola();
};

void Escola::mostrarEscola()
{
    std::cout << "Escola: " << nome << "\n";
}

void Escola::Turma::mostrarTurma()
{
    std::cout << "Turma: " << serie << "\n";
}

void Escola::Turma::Aluno::mostrarAluno()
{
    std::cout << "Aluno " << num_aluno << " -> " << "Nome: " << nomeAluno << ", Nota: " << nota << "\n";
}

int main()
{
    // Instâncias
    Escola e("UFC");
    Escola::Turma t("Engenharia de Computação");
    Escola::Turma::Aluno aluno1("Ana", 9.0);
    Escola::Turma::Aluno aluno2("Pedro", 7.0);
    // Operações
    Escola::Turma::Aluno aluno3 = aluno1 + aluno2;
    std::cout << aluno3;

    return 0;
}