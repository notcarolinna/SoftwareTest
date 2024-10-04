#include "unity.h"
#include "unity_fixture.h"
#include "../src/sort.h"

#define CERTO 0
#define ERRADO 1

// Vetores de teste
int vet_asc[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int vet_desc[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int vet_dup[12] = {3, 1, 2, 3, 2, 1, 3, 1, 2, 3, 2, 1};
int vet_neg[5] = {-1, -3, -2, -5, -4};
int vet_mixed[8] = {3, -1, 2, -3, 1, -2, 5, 0};

void teste(int* vet_base, int size, int compare);

TEST_GROUP(Sorting);

TEST_SETUP(Sorting){}

TEST_TEAR_DOWN(Sorting){}

// Testa vetor ascendente
TEST(Sorting, TestSortingAscending){
	teste(vet_asc, 10, CERTO);
	free(vet_asc);
}

// Testa vetor descendente
TEST(Sorting, TestSortingDescending){
	teste(vet_desc, 10, CERTO);
	free(vet_desc);
}

// Testa vetor com elementos repetidos
TEST(Sorting, TestSortingDuplicates){
	teste(vet_dup, 12, CERTO);
	free(vet_dup);
}

// Teste vetor com elementos negativos
TEST(Sorting, TestSortingNegative){
	teste(vet_neg, 5, CERTO);
	free(vet_neg);
}

// Teste vetor com elementos positivos e negativos
TEST(Sorting, TestSortingMixed){
	teste(vet_mixed, 8, CERTO);
	free(vet_mixed);
}

// Testa vetor com tamanho mínimo
TEST(Sorting, TestSortingMinSize){
	int *vet_min = malloc(2 * sizeof(int));
	if (vet_min != NULL) {
		vet_min[0] = 2; 
		vet_min[1] = 1;
		teste(vet_min, 2, CERTO);
    }
	free(vet_min);
}

// Testa vetor com tamanho máximo
TEST(Sorting, TestSortingMaxSize) {
	int *vet_max = malloc(20 * sizeof(int));
    if (vet_max != NULL) {
		// Preenche o vetor em ordem decrescente
        for (int i = 0; i < 20; i++) {
            vet_max[i] = 20 - i;
        }
		teste(vet_max, 20, CERTO);
    }
	free(vet_max);
}

// Testa um vetor com mais de 20 elementos (deve retornar erro)
TEST(Sorting, TestSortingInvalidSize) {
    int *vet_invalid = malloc(21 * sizeof(int));
    if (vet_invalid != NULL) {
        for (int i = 0; i < 21; i++) {
            vet_invalid[i] = 21 - i; // Preenche o vetor em ordem decrescente
        }
		teste(vet_invalid, 21, ERRADO);
    }
	free(vet_invalid);
}

void teste(int* vet_base, int size, int compare) {
	int status;
    int *vet = malloc(size * sizeof(int));
    if (vet != NULL) {
		// Counting Sort
        memcpy(vet, vet_base, size * sizeof(int));
        status = sort(vet, size, "Onlogn", COUNTING);
        TEST_ASSERT_EQUAL(compare, status);
		// Radix Sort
		memcpy(vet, vet_base, size * sizeof(int));
        status = sort(vet, size, "Onlogn", RADIX);
        TEST_ASSERT_EQUAL(compare, status);
		// Bubble Sort
		memcpy(vet, vet_base, size * sizeof(int));
        status = sort(vet, size, "Onlogn", BUBBLE);
        TEST_ASSERT_EQUAL(compare, status);
		// Insertion Sort
		memcpy(vet, vet_base, size * sizeof(int));
        status = sort(vet, size, "Onlogn", INSERTION);
        TEST_ASSERT_EQUAL(compare, status);
		// Selection Sort
		memcpy(vet, vet_base, size * sizeof(int));
        status = sort(vet, size, "Onlogn", SELECTION);
        TEST_ASSERT_EQUAL(compare, status);
		// Heap Sort
		memcpy(vet, vet_base, size * sizeof(int));
        status = sort(vet, size, "Onlogn", HEAP);
        TEST_ASSERT_EQUAL(compare, status);
		// Merge Sort
		memcpy(vet, vet_base, size * sizeof(int));
        status = sort(vet, size, "Onlogn", MERGE);
        TEST_ASSERT_EQUAL(compare, status);
		// Quick Sort
		memcpy(vet, vet_base, size * sizeof(int));
        status = sort(vet, size, "Onlogn", QUICK);
        TEST_ASSERT_EQUAL(compare, status);
    }
	free(vet);
}