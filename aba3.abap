  METHOD is_anagrem.

    DATA: lv_word1 TYPE string,
          lv_word2 TYPE string,

          lv_sorted1 TYPE string,
          lv_sorted2 TYPE string.

    lv_word1 = word1.
    lv_word2 = word2.

    TRANSLATE lv_word1 TO LOWER CASE.
    TRANSLATE lv_word2 TO LOWER CASE.
    CONDENSE lv_word1 NO-GAPS.
    CONDENSE lv_word2 NO-GAPS.


    me->sort_string(
      EXPORTING
        word      = lv_word1
      IMPORTING
        sort_word = lv_sorted1
    ).

    me->sort_string(
          EXPORTING
            word      = lv_word2
          IMPORTING
            sort_word = lv_sorted2
        ).

    IF lv_sorted1 = lv_sorted2.
      result = abap_true.
    ELSE.
      result = abap_false.
    ENDIF.

  ENDMETHOD.
