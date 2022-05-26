#include <iostream>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int len = 0;

struct Block_List {

    int idx;
    int start;
    int size;
    int finish;
    bool is_free;
    Block_List* previous;
    Block_List* next;
    
    Block_List(int idx, int start, int finish, bool is_free, Block_List* previous, Block_List* next) {
		this->idx = idx;
		this->start = start;
		this->finish = finish;
		this->is_free = is_free;
		this->previous = previous;
		this->next = next;
		if (previous) {
			previous->next = this;
		}
		if (next) {
			next->previous = this;
		}
	}
    
    void rid() {
        if (previous)
            previous->next = next;
        if (next)
            next->previous = previous;
    }
};

struct Block_List* blocks[100000];
struct Block_List* requested[100000];

int get_block_size(Block_List* block) {
    return 1 + block->finish - block->start;
}

void swap(int i, int j) {
    Block_List* tmp = blocks[i];
    blocks[i] = blocks[j];
    blocks[j] = tmp;
    blocks[i]->idx = i;
    blocks[j]->idx = j;
}

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void siftup(int i) {
    while (i > 0 && get_block_size(blocks[parent(i)]) < get_block_size(blocks[i])) {
        swap(i, parent(i));
        i = parent(i);
    }
}

void insert(Block_List* block) {
    block -> idx = len;
    blocks[len] = block;
    siftup(len++);
}

void siftdown(int i) {
    while (true) {
        int j = i;
        if (left(j) < len && get_block_size(blocks[i]) < get_block_size(blocks[left(j)])) {
            i = left(j);
        }
        if (right(j) < len && get_block_size(blocks[i]) < get_block_size(blocks[right(j)])) {
            i = right(j);
        }
        if (i != j) {
            swap(i, j);
        } else break;
    }
}

void extract(int i) {
    swap(i, --len);
    siftup(i);
    siftdown(i);
}

int main()
{
    int n, m;
    
    cin >> n >> m;
    
    struct Block_List* base = new Block_List(len++, 1, n, true, NULL, NULL);
    
    blocks[0] = base;
    
    for (int i = 0; i < m; i++) {
        int current;
        cin >> current;
        if (current > 0) {
            Block_List* maximum = blocks[0];
            if (!len || get_block_size(maximum) < current) {
                cout << -1 << endl;
            } else {
                cout << maximum->start << endl;
                requested[i] = new Block_List(-1, maximum->start, maximum->start + current - 1, false, maximum->previous, maximum);
                maximum->start += current;
                if (get_block_size(maximum)) {
                    siftdown(maximum->idx);
                } else {
                    maximum->rid();
                    swap(0, --len);
                    siftdown(0);
                }
            }
        } else {
            Block_List* free_req = requested[-current-1];
            if (free_req) {
                if (free_req->previous && free_req->next && free_req->previous->is_free && free_req->next->is_free) {
                    free_req->previous->finish = free_req->next->finish;
                    siftup(free_req->previous->idx);
                    free_req->rid();
                    extract(free_req->next->idx);
                    free_req->next->rid();
                }
                else if (free_req->previous && free_req->previous->is_free) {
                    free_req->previous->finish = free_req->finish;
                    siftup(free_req->previous->idx);
                    free_req->rid();
                }
                else if (free_req->next && free_req->next->is_free) {
                    free_req->next->start = free_req->start;
                    siftup(free_req->next->idx);
                    free_req->rid();
                } else {
                    free_req->is_free = true;
                    insert(free_req);
                }
            }
        }
    }
    
    return 0;
}
