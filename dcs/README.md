# C++
***(Modulo 07)***

## Index

01. **[Retornando referência](#funções-retornando-uma-referência)**
02. **[Exemplos de Codigos](#exemplos-de-codigos)**
03. **[Resources](#resources)**

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

## Resources
Resource | Source
---------|:-----:
[Templates tutorial](https://cplusplus.com/doc/oldtutorial/templates/) | `Site`