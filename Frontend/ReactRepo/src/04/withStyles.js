import ThemeStyleSheet from "react-with-styles/lib/ThemedStyleSheet";
import aphroditeInterface from "react-with-styles-interface-aphrodite";
import { css, withStyles, withStylesPropTypes } from "react-with-styles";
import Theme from "./Theme";

ThemeStyleSheet.registerTheme(Theme);
ThemeStyleSheet.registerInterface(aphroditeInterface);

export { css, withStyles, withStylesPropTypes, ThemeStyleSheet };
export default withStyles;
