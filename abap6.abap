  METHOD sort_string.

    DATA: lt_char TYPE TABLE OF char1,
          lv_char TYPE char1,
          lv_index TYPE i.

    DO strlen( word ) TIMES.
      lv_char = word+sy-index(1).
      APPEND lv_char TO lt_char.
    ENDDO.

    SORT lt_char.

    CLEAR: sort_word.

    LOOP AT lt_char INTO lv_char.
      CONCATENATE sort_word lv_char INTO sort_word.
    ENDLOOP.

  ENDMETHOD.
