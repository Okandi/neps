#include <bits/stdc++.h>

using namespace std;


void printDeque(deque<int> &container) { // O(n)
    for (int i=0; i<container.size(); i++) {
        cout << container[i] << " ";
    }
    cout << endl;
}


pair<deque<int>, deque<int>> divideContainer(deque<int> &container) {
    int containerSize = container.size();
    int firstContainerSize = (int) ceil((float) containerSize/2.);
    int secondContainerSize = containerSize/2;

    deque<int> firstContainer(firstContainerSize);
    copy(container.begin(), container.begin()+firstContainerSize, firstContainer.begin());

    deque<int> secondContainer(secondContainerSize);
    copy(container.begin()+firstContainerSize, container.begin()+firstContainerSize+secondContainerSize, secondContainer.begin());

    return {firstContainer, secondContainer};
}


deque<int> mergeContainer(deque<int> &firstContainer, deque<int> &secondContainer) { // O(n)
    deque<int> mergedContainer;
    while (!firstContainer.empty() || !secondContainer.empty()) {
        if (firstContainer.empty()) {
            mergedContainer.push_back(secondContainer.front());
            secondContainer.pop_front();
        } else if (secondContainer.empty()) {
            mergedContainer.push_back(firstContainer.front());
            firstContainer.pop_front();
        } else {
            if (firstContainer.front() > secondContainer.front()) {
                mergedContainer.push_back(secondContainer.front());
                secondContainer.pop_front();
            } else {
                mergedContainer.push_back(firstContainer.front());
                firstContainer.pop_front();
            }
        }
    }
    return mergedContainer;
}


void mergeSort(deque<int> &container) { // O(log(n)) => + mergeContainer => O(n*log(n))
    if (container.size() <= 1) return;

    pair<deque<int>, deque<int>> dividedContainers = divideContainer(container);

    mergeSort(dividedContainers.first);
    mergeSort(dividedContainers.second);

    container = mergeContainer(dividedContainers.first, dividedContainers.second);
}


int main() {
    int qtdNumeros;
    cin >> qtdNumeros;

    deque<int> container;
    for (int i=0; i<qtdNumeros; i++) {
        int numero;
        cin >> numero;
        container.push_back(numero);
    }

    mergeSort(container);

    printDeque(container);
}
