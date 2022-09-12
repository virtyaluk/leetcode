/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

struct Cmp {
    bool operator()(const PolyNode* lhs, const PolyNode* rhs) {
        return rhs->power >= lhs->power;
    }
};

class Solution {
private:
    
    
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode *dummy = new PolyNode(),
            *cur = dummy;
        // priority_queue<PolyNode*, vector<PolyNode*>, Cmp> pq;
        map<int, int, greater<>> pq;
        
        while (poly1) {
            pq[poly1->power] += poly1->coefficient;
            poly1 = poly1->next;
        }
        
        while (poly2) {
            pq[poly2->power] += poly2->coefficient;
            poly2 = poly2->next;
        }
        
        for (auto [power, coef]: pq) {
            if (not coef) {
                continue;
            }
            
            cur->next = new PolyNode(
                coef,
                power
            );
            cur = cur->next;
        }
        
        return dummy->next;
    }
};