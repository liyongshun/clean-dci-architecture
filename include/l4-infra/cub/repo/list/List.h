#ifndef H29B1191B_457B_4E80_8056_1233626F0A98
#define H29B1191B_457B_4E80_8056_1233626F0A98

#include <l4-infra/cub/cub.h>
#include <l4-infra/cub/repo/list/apr_ring.h>

CUB_NS_BEGIN

template<typename T>
struct List
{
   struct ReverseIterator
   {
      ReverseIterator() :
               elem(0), next(0)
      {
      }

      ReverseIterator(T* elem) :
               elem(elem), next(getNext(elem))
      {
      }

      ReverseIterator(const ReverseIterator& rhs) :
               elem(rhs.elem), next(rhs.next)
      {
      }

      ReverseIterator& operator=(const ReverseIterator& rhs)
      {
         elem = rhs.elem;
         next = rhs.next;

         return *this;
      }

      bool operator==(const ReverseIterator& rhs) const
      {
         return elem == rhs.elem;
      }

      bool operator!=(const ReverseIterator& rhs) const
      {
         return !(*this == rhs);
      }

      void reset()
      {
         elem = 0;
         next = 0;
      }

      bool isNull() const
      {
         return elem == 0;
      }

      T* operator->()
      {
         return elem;
      }

      T& operator*()
      {
         return *elem;
      }

      T* getValue() const
      {
         return elem;
      }

      ReverseIterator operator++(int)
      {
         ReverseIterator i = *this;

         elem = next;
         next = getNext(elem);

         return i;
      }

      ReverseIterator& operator++()
      {
         elem = next;
         next = getNext(elem);

         return *this;
      }

   private:
      static T* getNext(T* elem)
      {
         return elem == 0 ? 0 : List<T>::getPrev(elem);
      }

   private:
      T* elem;
      T* next;
   };

   struct Iterator
   {
      Iterator() :
               elem(0), next(0)
      {
      }

      Iterator(T* elem) :
               elem(elem), next(getNext(elem))
      {
      }

      Iterator(const Iterator& rhs) :
               elem(rhs.elem), next(rhs.next)
      {
      }

      Iterator& operator=(const Iterator& rhs)
      {
         elem = rhs.elem;
         next = rhs.next;

         return *this;
      }

      bool operator==(const Iterator& rhs) const
      {
         return elem == rhs.elem;
      }

      bool operator!=(const Iterator& rhs) const
      {
         return !(*this == rhs);
      }

      void reset()
      {
         elem = 0;
         next = 0;
      }

      bool isNull() const
      {
         return elem == 0;
      }

      T* operator->()
      {
         return elem;
      }

      T& operator*()
      {
         return *elem;
      }

      T* getValue() const
      {
         return elem;
      }

      Iterator operator++(int)
      {
         Iterator i = *this;

         elem = next;
         next = getNext(elem);

         return i;
      }

      Iterator& operator++()
      {
         elem = next;
         next = getNext(elem);

         return *this;
      }

   private:
      static T* getNext(T* elem)
      {
         return elem == 0 ? 0 : List<T>::getNext(elem);
      }

      static T* getPrev(T* elem)
      {
         return elem == 0 ? 0 : List<T>::getPrev(elem);
      }
   private:
      T* elem;
      T* next;
   };

   List() : num(0)
   {
       APR_RING_INIT(&head, T, link);
   }

   unsigned short size() const
   {
       return num;
   }

   void pushBack(T& elem)
   {
      APR_RING_INSERT_TAIL(&head, &elem, T, link);
      num++;
   }

   void pushFront(T& elem)
   {
      APR_RING_INSERT_HEAD(&head, &elem, T, link);
      num++;
   }

   void pushBack(Iterator& elem)
   {
      APR_RING_INSERT_TAIL(&head, &(*elem), T, link);
      num++;
   }

   void pushFront(Iterator& elem)
   {
	  APR_RING_INSERT_HEAD(&head, &(*elem), T, link);
      num++;
   }

   Iterator begin() const
   {
      return APR_RING_FIRST(&head);
   }

   Iterator end() const
   {
      return APR_RING_SENTINEL(&head, T, link);
   }

   ReverseIterator rbegin() const
   {
      return APR_RING_LAST(&head);
   }

   ReverseIterator rend() const
   {
      return APR_RING_SENTINEL(&head, T, link);
   }

   bool isLast(T* elem) const
   {
      return elem == APR_RING_LAST(&head);
   }

   bool isFirst(T* elem) const
   {
      return elem == APR_RING_FIRST(&head);
   }

   T* getLast() const
   {
      return isEmpty() ? 0 : APR_RING_LAST(&head);
   }

   T* getFirst() const
   {
      return isEmpty() ? 0 : APR_RING_FIRST(&head);
   }

   void insertAfter(const T* prev, T* elem)
   {
      APR_RING_INSERT_AFTER((T*)prev, elem, link);
      num++;
   }

   void insertAfterSafe(const T* prev, T* elem)
   {
      if(prev == 0) pushFront(*elem);
      else insertAfter(prev, elem);
   }

   void insertBefore(const T* prev, T* elem)
   {
      APR_RING_INSERT_BEFORE((T*)prev, elem, link);
      num++;
   }

   void insertBeforeSafe(const T* prev, T* elem)
   {
      if(prev == 0) pushBack(*elem);
      else insertBefore(prev, elem);
   }

   void moveTo(const T* prev, T* elem)
   {
      APR_RING_REMOVE(elem, link);
      APR_RING_INSERT_AFTER((T*)prev, elem, link);
   }

   T* popFront()
   {
      Iterator i = begin();
      if (i == end())
      {
         return 0;
      }

      erase(i);

      return &(*i);
   }

   void remove(T& elem)
   {
       APR_RING_REMOVE(&elem, link);
       num--;
   }

   void erase(Iterator elem)
   {
      if(elem.isNull()) return;

      remove(*elem);
   }

   bool isEmpty() const
   {
      return APR_RING_EMPTY(&head, T, link);
   }

   void clear()
   {
      while(popFront() != 0);
   }

   unsigned short getSize() const
   {
      return num;
   }

   void reset()
   {
      T* p = 0;

      while((p = popFront()) != 0)
      {
         delete p;
      }
   }

   void moveToAfterSafe(const T* prev, T* elem)
   {
      remove(*elem);
      insertAfterSafe(prev, elem);
   }

   void moveToBeforeSafe(const T* next, T* elem)
   {
      remove(*elem);
      insertBeforeSafe(next, elem);
   }

   /////////////////////////////////////////////////////////
   template <typename _PRED>
   T* search(_PRED pred) const
   {
      APR_RING_FOREACH(i, &head, T, link)
      {
         if(pred(*i))
         {
            return i;
         }
      }

      return 0;
   }

   /////////////////////////////////////////////////////////
   template <typename _PRED>
   T* searchFrom(const T* from, _PRED pred) const
   {
      if(from == 0) return 0;

      APR_RING_FOREACH_FROM(i, (T*)from, &head, T, link)
      {
         if(pred(*i))
         {
            return i;
         }
      }

      return 0;
   }

   /////////////////////////////////////////////////////////
   template <typename _PRED>
   T* searchFromR(const T* from, _PRED pred) const
   {
       if(from == 0) return 0;

       APR_RING_FOREACH_FROM_R(i, (T*)from, &head, T, link)
      {
         if(pred(*i))
         {
            return i;
         }
      }

      return 0;
   }

   /////////////////////////////////////////////////////////
   void concat(List<T>& another)
   {
       APR_RING_CONCAT(&head, &another.head, T, link);
       num += another.size();
       another.num = 0;
   }

   void unsplice(const Iterator& i, List<T>& to)
   {
	   T* last = APR_RING_LAST(&head);
	   APR_RING_UNSPLICE(i.getValue(), APR_RING_LAST(&head), link);
	   APR_RING_SPLICE_AFTER(APR_RING_FIRST(&to.head), i.getValue(), last, link);
   }

   /////////////////////////////////////////////////////////
   Iterator getNext(Iterator& i) const
   {
       return (i == end()) ? end() : ++i;
   }

private:
   static T* getNext(T* elem)
   {
      return elem->link.next;
   }

   static T* getPrev(T* elem)
   {
      return elem->link.prev;
   }

private:
   APR_RING_HEAD(T) head;
   unsigned short num;
};

/////////////////////////////////////////////////////////////
#define LIST_FOREACH_FROM(type, i, from, items) \
   for(typename CUB_NS::List<type>::Iterator i=from; i != items.end(); ++i)

#define LIST_FOREACH_FROM_R(type, i, from, items) \
   for(typename CUB_NS::List<type>::ReverseIterator i=from; i != items.rend(); ++i)

#define LIST_FOREACH(type, i, items) \
   LIST_FOREACH_FROM(type, i, items.begin(), items)

#define LIST_FOREACH_R(type, i, items) \
   for(typename CUB_NS::List<type>::ReverseIterator i=items.rbegin(); i != items.rend(); ++i)

/////////////////////////////////////////////////////////////////////////
#define LIST_FOREACH_FROM_SAFE(type, i, j, from, items) \
   for(typename CUB_NS::List<type>::Iterator i=from, j=++from; i != items.end(); i=j, ++j)

#define LIST_FOREACH_SAFE(type, i, j, items) \
   LIST_FOREACH_FROM_SAFE(type, i, j, items.begin(), items)

CUB_NS_END

#endif

