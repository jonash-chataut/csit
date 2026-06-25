<!DOCTYPE html>
<html>

<head>

    <title>Simple Website Using Include and Require</title>

</head>

<body>

    <?php

        /* Include Header File */
        include "header.php";

    ?>

    <h2>Home Page</h2>

    <p>
        Welcome to my simple website created
        using include and require statements.
    </p>

    <?php

        /* Require Footer File */
        require "footer.php";

    ?>

</body>

</html>