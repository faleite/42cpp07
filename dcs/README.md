# C++
***(Modulo 07)***

## Index

01. **[Exemplos de Codigos](#exemplos-de-codigos)**
01. **[Templates typename vs class](#templates-typename-vs-class)**
03. **[Retornando referência](#funções-retornando-uma-referência)**
04. **[Resources](#resources)**

## *Exemplos de codigos*

- *Aqui está exmplos de `functions templates` e `class templates`:*

```cpp
// Function Templates
template <class T>
T& getMax(T &a, T &b)
{
	T result;
	result = (a > b) ? a : b;
	return (result);
}

// Function Templates
template <class T, class U>
T& getMin(T &a, &U b)
{
	return ((a < b) ? a : b);
}

// Class Templates

/**
 * @brief Stores two values ​​of the same type.
 */
template <class T>
class myPair
{
	private:
		T values[2];
		T a, b;
	public:
		myPair(T first, T second)
		{
			values[0] = first;
			values[1] = second;
			a = first;
			b = second;
		}
		void getData(void);
		T getMax();
};

template <class T>
T myPair<T>::getMax()
{
	T retVal;
	retVal = a > b ? a : b;
	return (retVal);
}

template <class T>
void myPair<T>::getData()
{
	std::cout << "Data: " << values[0] 
	<< " and " << values[1] << std::endl; 
}

int	main(void)
{
	// Used function templates:
	std::cout << "functions templates" << std::endl;
	{
		int i = 5, j = 6, k;
		long l = 10, m = 5, n;
	
		// k = getMax<int>(i, j);
		// n = getMax<long>(l, m);
		k = getMax(i, j);
		n = getMax(l, m);
	
		std::cout << k << std::endl;
		std::cout << n << std::endl;
	}
	{
		int i, j = 3;
		long l = 7;

		// i = getMin<int, long>(j, l);
		i = getMin(j, l);
		std::cout << i << std::endl;
	}
	
	// Used class templates:
	std::cout << "class templates" << std::endl;
	{
		myPair<int> myObject(115, 36);
		myPair<double> myFloats(3.01, 2.18);
		
		myObject.getData();
		myFloats.getData();
		std::cout << myObject.getMax() << std::endl;
	}
	return (0);
}
```

[↑ Index ↑](#index)

## Templates typename vs class
- A diferença entre `template <typename T>` e `template <class T>` é puramente sintática. Ambos são equivalentes e podem ser usados de forma intercambiável para declarar templates em C++.

**Detalhes:**

- `template <typename T>`: Introduzido para tornar o código mais intuitivo, especialmente para novos programadores. A palavra typename sugere que T é um tipo.
- `template <class T>`: É a forma original de declarar templates em C++. A palavra `class` não significa que `T` deve ser uma classe; pode ser qualquer tipo (classe, struct, tipo primitivo, etc.).

**Quando usar:**
- **Preferência pessoal ou convenção do projeto:** Escolha uma e seja consistente. Em muitos projetos, a escolha entre `typename` e `class` é baseada em convenções de codificação ou preferências pessoais.
- **Legibilidade:** Alguns desenvolvedores preferem `typename` para deixar claro que `T` é um tipo, especialmente em contextos onde a palavra `class` pode ser confusa.

Você, no entanto, tem que usar `class` (e não `typename`) ao declarar um parâmetro de template de template:
```cpp
template <template <typename> class    T> class C { }; // valid!
template <template <typename> typename T> class C { }; // invalid!  o noez!
```

[↑ Index ↑](#index)

## Funções retornando uma referência
*Razões para Retornar uma Referência*

1. **Evitar Cópias Desnecessárias:**
  - Retornar uma referência evita a criação de uma cópia do objeto. Isso pode ser mais eficiente, especialmente para tipos grandes ou complexos.
  - Quando você retorna uma referência, você está retornando um "apelido" para o objeto original, não uma nova instância.
2. **Permitir Modificações no Objeto Original:**
  - Retornar uma referência permite que o chamador modifique o objeto original. Isso pode ser útil em alguns casos onde você deseja alterar o valor do maior dos dois objetos.

*Exemplo:*
```cpp
int x = 10;
int y = 20;
max(x, y) = 30; // Isso modifica 'y' para 30, pois 'y' é o maior
```
3. **Consistência com o Uso de Referências nos Parâmetros:**
  - Se você está passando os parâmetros por referência, faz sentido retornar uma referência também, para manter a consistência e evitar cópias desnecessárias.

*Exemplo de uso:*
```cpp
#include <iostream>

template <typename T>
T& max(T &a, T &b)
{
    return (a > b) ? a : b;
}

int main()
{
    int x = 10;
    int y = 20;

    std::cout << "Max: " << max(x, y) << std::endl;

    // Modificando o maior valor
    max(x, y) = 30;
    std::cout << "x: " << x << ", y: " << y << std::endl;

    return 0;
}
```
[↑ Index ↑](#index)

## Resources
Resource | Source
---------|:-----:
[Templates tutorial](https://cplusplus.com/doc/oldtutorial/templates/) | `Site`