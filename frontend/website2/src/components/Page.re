module Footer = {
  module Link = {
    let footerStyle =
      Css.(
        style([
          Theme.Typeface.ibmplexsans,
          color(Theme.Colors.slate),
          textDecoration(`none),
          display(`inline),
          hover([color(Theme.Colors.hyperlink)]),
          fontSize(`rem(1.0)),
          fontWeight(`light),
          lineHeight(`rem(1.56)),
        ])
      );
    [@react.component]
    let make = (~last=false, ~link, ~name, ~children) => {
      <li className=Css.(style([display(`inline)]))>
        <a
          href=link
          className=footerStyle
          name={"footer-" ++ name}
          target="_blank">
          children
        </a>
        {last
           ? React.null
           : <span className=footerStyle ariaHidden=true>
               {React.string({js| · |js})}
             </span>}
      </li>;
    };
  };

  [@react.component]
  let make = (~bgcolor) => {
    <footer className=Css.(style([backgroundColor(bgcolor)]))>
      <section
        className=Css.(
          style(
            [
              maxWidth(`rem(96.0)),
              marginLeft(`auto),
              marginRight(`auto),
              // Not using Theme.paddingY here because we need the background
              // color the same (so can't use margin), but we also need some
              // top spacing.
              paddingTop(`rem(4.75)),
              paddingBottom(`rem(2.)),
            ]
            @ Theme.paddingX(`rem(4.0)),
          )
        )>
        <div
          className=Css.(
            style([
              display(`flex),
              justifyContent(`center),
              textAlign(`center),
              marginBottom(`rem(2.0)),
            ])
          )>
          <ul
            className=Css.(
              style([listStyleType(`none), ...Theme.paddingX(`zero)])
            )>
            <Link link="mailto:contact@o1labs.org" name="mail">
              {React.string("contact@o1labs.org")}
            </Link>
            <Link link="https://o1labs.org" name="o1www">
              {React.string("o1labs.org")}
            </Link>
            <Link link="https://twitter.com/codaprotocol" name="twitter">
              {React.string("Twitter")}
            </Link>
            <Link link="https://github.com/CodaProtocol/coda" name="github">
              {React.string("GitHub")}
            </Link>
            <Link link="https://forums.codaprotocol.com" name="discourse">
              {React.string("Discourse")}
            </Link>
            <Link link="https://reddit.com/r/coda" name="reddit">
              {React.string("Reddit")}
            </Link>
            <Link link="https://t.me/codaprotocol" name="telegram">
              {React.string("Telegram")}
            </Link>
            <Link link="/tos" name="tos">
              {React.string("Terms of service")}
            </Link>
            <Link link="/privacy" name="privacy">
              {React.string("Privacy Policy")}
            </Link>
            <Link link="/jobs" name="hiring">
              {React.string("We're Hiring")}
            </Link>
            <Link link="/static/presskit.zip" name="presskit" last=true>
              {React.string("Press Kit")}
            </Link>
          </ul>
        </div>
        <p
          className=Css.(
            merge([
              Theme.Body.small,
              style([textAlign(`center), color(Theme.Colors.saville)]),
            ])
          )>
          {React.string({j|© 2019 O(1) Labs|j})}
        </p>
      </section>
    </footer>;
  };
};

[@react.component]
let make = (~children, ~footerColor=Theme.Colors.white) => {
  <>
    <Next.Head>
      <link
        href="https://cdn.jsdelivr.net/npm/@ibm/plex@4.0.2/css/ibm-plex.min.css"
        rel="stylesheet"
      />
      <link href="https://use.typekit.net/mta7mwm.css" rel="stylesheet" />
    </Next.Head>
    <Nav />
    <div> children </div>
    <Footer bgcolor=footerColor />
  </>;
};
