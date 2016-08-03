//Hi this is a prototype
template <class T>
Set<T> operator && (Set<T> rhs)
{
   iSet1 = 0;
   iSet2 = 0;
   
   Set<T> setReturn;
   while ( iSet1 < numItems || iSet < rhs.size())
   {
      if (iSet1 == numItems)
         return SetReturn;
      else if ( iSet2 == rhs.size())
         return setReturn;
      else if ( data[iSet1] == rhs.getData(iSet2))
      {
         setReturn.insert(data[iSet1]);
         iSet1++;
         iset2++;
      }
      else if (data[iSet1] < rhs.getData(iSet2))
         iSet1++;
      else
         iSet2++;
   }
   
   return setReturn;
}
