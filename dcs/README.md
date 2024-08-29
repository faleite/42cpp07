# C++
***(Modulo 06)***

## Index

01. **[static_cast](#static_cast)**
02. **[reinterpret_cast](#reinterpret_cast)**
03. **[dynamic_cast](#dynamic_cast)**
04. **[Resources](#resources)**

## static_cast
*`static_cast` é um operador de casting que permite a conversão explícita de um tipo de dado para outro. Ele é mais seguro e controlado do que os casts tradicionais em C (como `(int)x`), pois* ***realiza verificações em tempo de compilação.***

### O `static_cast` é usado para:
- Conversões entre tipos primitivos (por exemplo, de `int` para `float`).
- Conversões entre ponteiros de classes relacionadas por herança.
- Conversões explícitas entre tipos de dados compatíveis.

### Como funciona?
- O `static_cast` realiza a conversão em tempo de compilação, garantindo que a conversão seja válida e segura. No entanto, ele não realiza verificações em tempo de execução, então o programador deve garantir que a conversão faz sentido.

### Exemplos

Aqui está um exemplo simples de como usar `static_cast`:

```cpp
#include <iostream>

int main() {
    // Conversão entre tipos primitivos
    int i = 10;
    float f = static_cast<float>(i);
    std::cout << "Valor de f: " << f << std::endl;

    // Conversão entre ponteiros de classes relacionadas por herança
    class Base {
    public:
        virtual void show() { std::cout << "Base class" << std::endl; }
    };

    class Derived : public Base {
    public:
        void show() override { std::cout << "Derived class" << std::endl; }
    };

    Base* basePtr = new Derived();
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    derivedPtr->show(); // Output: Derived class

    delete basePtr;
    return 0;
}
```

### Pontos importantes
- **Segurança em tempo de compilação**: O `static_cast` garante que a conversão é válida em tempo de compilação.
- **Sem verificações em tempo de execução**: Diferente do `dynamic_cast`, o `static_cast` não realiza verificações em tempo de execução, então o programador deve garantir que a conversão é segura.
- **Uso em herança**: Pode ser usado para converter ponteiros ou referências entre classes base e derivadas.

### Quando usar `static_cast`?
Use `static_cast` quando você tem certeza de que a conversão é segura e válida, e quando você precisa de uma conversão mais controlada e explícita do que os casts tradicionais em C.

[↑ Index ↑](#index)

## Promotion Casts
*Promotion casts referem-se a conversões automáticas que o compilador realiza para promover um tipo de dado a um tipo maior ou mais abrangente. Isso geralmente ocorre em operações aritméticas. Por exemplo:*
- **Inteiro para float**: Quando você soma um **int** e um float, o **int** é promovido a **float**.
- **Char para int**: Quando você usa um **char** em uma expressão aritmética, ele é promovido a **int**.

### Conversões Implícitas
Conversões implícitas são aquelas que o compilador realiza automaticamente, sem a necessidade de um cast explícito. 

### Eexemplo:
```cpp
int i = 42;
float f = i; // Conversão implícita de int para float
```
### O que a frase quer dizer?
A frase "Accept the use of implicit casts for promotion casts only." sugere que você deve permitir que o compilador realize conversões implícitas apenas quando se trata de promotion casts. Para outras conversões, você deve usar casts explícitos, como static_cast, para deixar claro que a conversão é intencional e segura.

### Exemplo

Aqui está um exemplo que ilustra a diferença:
```cpp
#include <iostream>

void example() {
    int i = 42;
    float f = i; // Permitido: promoção implícita de int para float

    double d = 3.14;

    // Recomendado:
    // uso de static_cast para conversão explícita de double para int
    int j = static_cast<int>(d); 
}

int main() {
    example();
    return 0;
}
```

### Resumo
- **Promotion casts**: Permita conversões implícitas apenas para promoções automáticas de tipos menores para tipos maiores.
- **Outras conversões**: Use casts explícitos (`static_cast`, `dynamic_cast`, etc.) para deixar claro que a conversão é intencional.

*Essa abordagem ajuda a evitar erros sutis e torna o código mais legível e seguro.*

### Classe sem dados e nao instanciavel
*Para criar uma classe canônica ortodoxa em C++ que não precisa armazenar nada e não deve ser instanciável pelos usuários, você pode seguir alguns passos:*

- **Tornar o construtor privado**: Isso impede que os usuários instanciem a classe diretamente.
- **Declarar um destrutor privado**: Isso impede a destruição da instância fora da classe.
- **Declarar um construtor de cópia e um operador de atribuição como privados e não implementados**: Isso impede a cópia da instância.

[↑ Index ↑](#index)

## reinterpret_cast
O **reinterpret_cast** é um operador de casting em C++ que permite a conversão de um ponteiro de um tipo para outro tipo de ponteiro, ou de um tipo de referência para outro tipo de referência. Ele é usado para realizar conversões que não são necessariamente seguras, mas que o programador garante que são válidas. O **reinterpret_cast** não realiza verificações de segurança em tempo de compilação ou execução, confiando inteiramente no programador.

### Como Funciona
1. Conversão de Ponteiros:
    - Permite converter um ponteiro de um tipo para outro tipo de ponteiro.
    - Exemplo:
    ```cpp
    float a = 420.042f;
    void *b = &a; // Conversão implícita de float* para void*
    int *c = reinterpret_cast<int *>(b); // Conversão explícita de void* para int*
    ```
2. Conversão de Referências:
    - Permite converter uma referência de um tipo para outro tipo de referência.
    - Exemplo:
    ```cpp
    int &d = reinterpret_cast<int &>(b); // Conversão explícita de void* para int&
    ```
3. Uso com Tipos Inteiros:
    - Pode ser usado para converter ponteiros para tipos inteiros e vice-versa.
    - Exemplo:
    ```cpp
    uintptr_t intPtr = reinterpret_cast<uintptr_t>(b); // Conversão de void* para uintptr_t
    void *ptr = reinterpret_cast<void *>(intPtr); // Conversão de uintptr_t para void*
    ```
### Exemplos no Código
```cpp
int	exemplo1(void)
{
	float a = 420.042f; // reference value

	void * b = &a; // implicit promotion -> ok
	int * c = reinterpret_cast<int *>(b); // explicit demotion -> ok
	// there will be no semantics checks, as the compiler will trust you
	// they will reinterpret any address as the specified other type
	int & d = reinterpret_cast<int &>(b); // explicit demotion -> ok
	
	std::cout << "a: " << a
	<< "\nb: " << b
	<< "\nc: " << *c
	<< "\nd: " <<  d << std::endl;
	
	return (0);
}

int	exemplo2(void)
{
	int a = 70; // F -> 70 char  reinterpret cast
	std::cout << "a: " << a << std::endl;

	int *ptr1 = &a;
	char *cptr = reinterpret_cast<char *>(ptr1);
	std::cout << "cptr: " << *cptr << std::endl;

	int *ptr2 = reinterpret_cast<int *>(a);
	std::cout << "ptr2: " << ptr2 << std::endl;
	
	// error: cast from 'int*' to 'int' loses precision [-fpermissive]
	// 						\/
	// std::cout << reinterpret_cast<int>(ptr2) << std::endl; // int(4) <- int*(8)
	std::cout << sizeof(int *) << " " << sizeof(int) << " " << sizeof(long) << std::endl;
	std::cout << reinterpret_cast<long>(ptr2) << std::endl; // int(4) <- int*(8)
 	 
	return (0);
}

int exemplo3(void)
{
	/*
	 memory
	 
		|----| int 4b
		|----| int 4b
		|-   | char 1b
		|-   | bool 1b
		
	 Total 12b
	*/
	struct Data
	{ 
		int		number1;
		int		number2;
		char	charactere;
		bool	boolean;
	};

	Data d;
	
	d.number1 = 70;
	d.number2 = 65;
	d.charactere = 'F';
	d.boolean = true;

	int *ptr_d = reinterpret_cast<int *>(&d);
	std::cout << *ptr_d << std::endl;
	ptr_d++;
	std::cout << *ptr_d << std::endl;
	ptr_d++;
	
	char *ptr_c = reinterpret_cast<char *>(ptr_d);
	std::cout << *ptr_c << std::endl;
	ptr_c++;
	
	bool *ptr_b = reinterpret_cast<bool *>(ptr_c);
	std::cout << *ptr_b << std::endl;
	
	return (0);
}
```

### Pontos Importantes
- **Segurança**: O `reinterpret_cast` não garante a segurança da conversão. O programador deve garantir que a conversão é válida.
- **Uso Comum**: É comumente usado em sistemas de baixo nível, como drivers de hardware, onde é necessário manipular diretamente endereços de memória.
- **Portabilidade**: O uso de `reinterpret_cast` pode tornar o código menos portátil, pois depende da representação interna dos tipos.

[↑ Index ↑](#index)

## dynamic_cast

`dynamic_cast` é um operador de casting que permite a conversão segura de ponteiros e referências de classes base para classes derivadas em tempo de execução. Ele é usado principalmente em hierarquias de classes polimórficas.

O `dynamic_cast` é usado para:
- Conversões seguras entre ponteiros e referências de classes relacionadas por herança.
- Verificar a validade de uma conversão em tempo de execução, retornando nullptr para ponteiros ou lançando uma exceção std::bad_cast para referências se a conversão não for possível.

**Como funciona?**

O `dynamic_cast` realiza verificações em tempo de execução para garantir que a conversão seja válida. Isso é especialmente útil em hierarquias de classes polimórficas onde a conversão pode falhar.

*Exemplos*
Aqui está um exemplo simples de como usar `dynamic_cast`:

```cpp
#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() {} // Necessário para que dynamic_cast funcione corretamente
};

class Derived : public Base {
public:
    void show() { std::cout << "Derived class" << std::endl; }
};

class Unrelated {};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr) {
        derivedPtr->show(); // Output: Derived class
    } else {
        std::cout << "Conversion failed" << std::endl;
    }

    // Tentativa de conversão inválida
    Base* anotherBasePtr = new Base();
    Derived* anotherDerivedPtr = dynamic_cast<Derived*>(anotherBasePtr);

    if (anotherDerivedPtr) {
        anotherDerivedPtr->show();
    } else {
        std::cout << "Conversion failed" << std::endl; // Output: Conversion failed
    }

    // Conversão de referência
    try {
        Base& baseRef = *basePtr;
        Derived& derivedRef = dynamic_cast<Derived&>(baseRef);
        derivedRef.show(); // Output: Derived class
    } catch (const std::bad_cast& e) {
        std::cout << "Bad cast: " << e.what() << std::endl;
    }

    delete basePtr;
    delete anotherBasePtr;
    return 0;
}
```

**Pontos importantes**
- Verificações em tempo de execução: O dynamic_cast garante que a conversão é válida em tempo de execução, retornando nullptr para ponteiros ou lançando uma exceção std::bad_cast para referências se a conversão falhar.
- Uso em hierarquias polimórficas: O dynamic_cast só funciona com classes que possuem pelo menos uma função virtual, geralmente o destrutor virtual.
- Custo de desempenho: Devido às verificações em tempo de execução, o dynamic_cast pode ser mais lento do que outros tipos de casting.

**Quando usar `dynamic_cast`?**

Use `dynamic_cast` quando você precisa de uma conversão segura entre tipos em uma hierarquia de classes polimórficas e quando você precisa garantir que a conversão é válida em tempo de execução.

## Resources
Resource | Source
---------|:-----:
[Type Casting](https://youtube.com/playlist?list=PL1w8k37X_6L-KS5DQt7U0rCtgIgdIadWz&si=v7aaa5tKTrmOP7nv) | `YouTube`