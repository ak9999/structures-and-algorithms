# algorithms.py

def selection_sort(container):
    '''Selection sort function.'''
    for element in range(len(container)):
        minimum_element = element
        for next_element in range(element+1, len(container)):
            if container[next_element] < container[minimum_element]:
                minimum_element = next_element
        container[minimum_element], container[element] = container[element], container[minimum_element]
