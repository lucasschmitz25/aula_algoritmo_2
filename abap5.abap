  METHOD reverse_string.

    DATA: lv_length TYPE i,
          lv_index  TYPE i,
          lv_char   TYPE char1,
          lv_ind    TYPE i.

    lv_length = strlen( word ).

    DO lv_length TIMES.
      lv_ind  = lv_length - sy-index.
      lv_char = word+lv_ind(1).
      CONCATENATE word_reversed lv_char INTO word_reversed.
    ENDDO.

  ENDMETHOD.
