#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_;
  int m_;
  PComparator c_;

};

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
  : m_(m)
{
  c_=c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
    data_.push_back(item);
    //trickleup
    int indexOfItem = data_.size()-1;
    int indexOfParent = (indexOfItem-1)/m_;

    while(c_(data_[indexOfItem],data_[indexOfParent]))
    {
      T& parent = (data_[indexOfParent]);
      T& current = (data_[indexOfItem]);
      std::swap(current,parent);
      indexOfItem = indexOfParent;
      indexOfParent = (indexOfItem-1)/m_;
    }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty stack");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty stack");

  }
  std::swap(data_[0],data_[data_.size()-1]);
  data_.pop_back();

  //trickledown
  std::size_t currIndex = 0;
  std::size_t bestChild = 0;
  bool sorted = false;

  while (sorted == false)
  {
    //checks to make sure its not already at the final level of the tree
    //which is if first possible child is greater than or = size
    while(currIndex*m_+1<data_.size())
    {
      sorted = true;
      
      //sets a default child for finding the best
      bestChild = currIndex*m_+1;

      //loops through the children, as long as they exist!
      for(int x=0; x<m_ && (currIndex*m_+x+1) < data_.size(); x++)
      {
        if(c_(data_[currIndex*m_+x+1],data_[currIndex]))
        {
          //if any child is out of order, set sorted to false
          sorted = false;
          //if a child found is better, record it.
          if(c_(data_[currIndex*m_+x+1],data_[bestChild]))
          {
            bestChild = currIndex*m_+x+1;
          }
        }
      }
      //if child not out of order just end the whole thing
      if(sorted == true)
      {
        break;
      }
      //swap with best child
      std::swap(data_[currIndex],data_[bestChild]);
      currIndex = bestChild;
    }
    break;
  }


}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
    return data_.size()==0;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
    return data_.size();
}


#endif

