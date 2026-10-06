typedef struct {
    stack<int> prices;
    stack<int> spans;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    stockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    heap<int> maxHeap;
    maxHeap.push(price);
    int span = 1;
    while (!maxHeap.empty() && maxHeap.top() <= price) {
        maxHeap.pop();
        span++; 
    }
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    delete obj;
}

int main() {
    StockSpanner* obj = stockSpannerCreate();
    int price = 100; // Example price
    int span = stockSpannerNext(obj, price);
    printf("Span for price %d: %d\n", price, span);
    stockSpannerFree(obj);
    return 0;
}