.. Iterators/Iterator Metafunctions//deref |50

deref
=====

Synopsis
--------

.. parsed-literal::
    
    template<
          typename Iterator
        >
    struct deref
    {
        typedef |unspecified| type;
    };



Description
-----------

Dereferences an iterator.


Header
------

.. parsed-literal::
    
    #include <boost/mpl/deref.hpp>



Parameters
----------

+---------------+---------------------------+-----------------------------------+
| Parameter     | Requirement               | Description                       |
+===============+===========================+===================================+
| ``Iterator``  | |Forward Iterator|        | The iterator to dereference.      |
+---------------+---------------------------+-----------------------------------+


Expression semantics
--------------------

For any |Forward Iterator|\ s ``iter``:


.. parsed-literal::

    typedef deref<iter>::type t; 

:Return type:
    A type.

:Precondition:
    ``iter`` is dereferenceable.

:Semantics:
    ``t`` is identical to the element referenced by ``iter``. If ``iter`` is
    a user-defined iterator, the library-provided default implementation is 
    equivalent to

    .. parsed-literal::
    
        typedef iter::type t;

    


Complexity
----------

Amortized constant time.


Example
-------

.. parsed-literal::
    
    typedef vector<char,short,int,long> types;
    typedef begin<types>::type iter;
    
    BOOST_MPL_ASSERT(( is_same< deref<iter>::type, char > ));


See also
--------

|Iterators|, |begin| / |end|, |next|
